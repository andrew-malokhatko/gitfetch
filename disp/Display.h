#pragma once

#include "parse/Parser.hpp"

namespace disp
{

class Display
{
    std::string_view defaultAsciiArt = R"(
  ______   ______  ________
 /      \ |      \|        \
|  $$$$$$\ \$$$$$$ \$$$$$$$$
| $$ __\$$  | $$     | $$
| $$|    \  | $$     | $$
| $$ \$$$$  | $$     | $$
| $$__| $$ _| $$_    | $$
 \$$    $$|   $$ \   | $$
  \$$$$$$  \$$$$$$    \$$
)";

public:
    void printHelp();
    void printVersion();
    void printUsage();

    void printData(const data::GitData& gitData);
};

}