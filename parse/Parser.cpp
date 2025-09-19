#include "Parser.hpp"

#include <array>
#include <cassert>
#include <fstream>
#include <memory>
#include <regex>

namespace parse
{
Parser::Parser(const fs::path& root) : path(root)
{
    auto gitPath = path / ".git";

    if (!fs::exists(gitPath))
    {
        throw std::runtime_error("Runtime Error: '.git' was not found.");
    }

    if (!fs::is_directory(gitPath))
    {
        throw std::runtime_error("Runtime Error: '.git' is not a directory.");
    }

    gitData.name = getRepoName();
    gitData.remote = getRemote();
    gitData.user = getUser();
    gitData.branch = getBranchName();
    gitData.commitCount = getCommitCount();
    gitData.commit = getLastCommit();
}

Parser::~Parser() {}

std::string Parser::runGitCommand(const std::string& command)
{
    //std::string commandStr = command + " -C " + path.string();

    std::string result{};
    std::array<char, 4096> buffer{};

    // open pipe
    // TODO: add multiplatform support for windows (_popen, _pclose)
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);

    while (fgets(buffer.data(), buffer.size(), pipe.get()))
    {
        result += buffer.data();
    }

    if (!result.empty() && result.back() == '\n')
    {
        result.pop_back();
    }

    return result;
}

std::string Parser::constructGitCommand(const std::string& command)
{
    std::string result{command};

    assert(result.starts_with("git "));
    result.insert(3, " -C " + path.string());

    return result;
}

std::string Parser::getRepoName()
{
    return path.filename();
}

std::string Parser::getRemote()
{
    std::string command = constructGitCommand("git config --get remote.origin.url");
    std::string output = runGitCommand(command);
    return output;
}

std::string Parser::getUser()
{
    std::string command = constructGitCommand("git config user.name");
    std::string output = runGitCommand(command);
    return output;
}

std::string Parser::getBranchName()
{
    std::string command = constructGitCommand("git rev-parse --abbrev-ref HEAD");
    std::string output = runGitCommand(command);
    return output;
}

size_t Parser::getCommitCount()
{
    std::string command = constructGitCommand("git rev-list --count HEAD");
    std::string output = runGitCommand(command);
    size_t count = std::stoi(output);
    return count;
}

CommitInfo Parser::getLastCommit()
{
    CommitInfo lastCommit{};
    std::string command = constructGitCommand("git log -1");
    std::string output = runGitCommand(command);

    // TODO: optimizations
    std::regex authorRegex(R"(^Author:\s+(.+?)\s+<(.+?)>$)", std::regex::multiline);
    std::regex dateRegex(R"(^Date:\s+(.*)$)", std::regex::multiline);
    std::regex messageRegex(R"(^\s+(.*)$)", std::regex::multiline);

    std::smatch match;

    if (std::regex_search(output, match, authorRegex))
    {
        lastCommit.author = match[1].str();
        lastCommit.email = match[2].str();
    }

    if (std::regex_search(output, match, dateRegex))
    {
        lastCommit.date = match[1];
    }

    if (std::regex_search(output, match, messageRegex))
    {
        lastCommit.message = match[1];
    }

    return lastCommit;
}

GitData Parser::getData()
{
    return gitData;
}

}