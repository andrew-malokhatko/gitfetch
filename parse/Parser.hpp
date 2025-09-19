#pragma once

#include <filesystem>

#include "GitData.hpp"

namespace parse
{

namespace fs = std::filesystem;

class Parser
{
    fs::path path{};
    GitData gitData{};

private:
    std::string runGitCommand(const std::string& command);
    std::string constructGitCommand(const std::string& command);

    std::string getRepoName();
    std::string getRemote();
    std::string getUser();
    std::string getBranchName();
    size_t getCommitCount();
    CommitInfo getLastCommit();

public:
    Parser(const fs::path& root = "");
    ~Parser();

    GitData getData();
};

}  // namespace parse