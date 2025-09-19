#pragma once

#include <string>

struct CommitInfo
{
    std::string author;
    std::string email;
    std::string date;
    std::string message;
};

struct GitData
{
    std::string name{};
    std::string remote{};
    std::string user{};
    std::string branch{};

    size_t commitCount{};
    CommitInfo commit{};
};
