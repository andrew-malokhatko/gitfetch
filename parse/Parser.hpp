#pragma once

#include <filesystem>

#include "data/GitData.hpp"

namespace parse
{

namespace fs = std::filesystem;

class Parser
{
    fs::path path{};
    data::GitData gitData{};

private:
    std::string runGitCommand(const std::string& command);
    std::string constructGitCommand(const std::string& command);

    std::string getRepoName();
    std::string getRemote();
    std::string getUser();
    std::string getBranchName();
    size_t getCommitCount();
    data::CommitInfo getLastCommit();

public:
    Parser(const fs::path& root = "");
    ~Parser();

    data::GitData getData();
};

}  // namespace parse