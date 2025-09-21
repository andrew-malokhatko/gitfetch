#pragma once

#include "data/GitData.hpp"

namespace disp
{

static const std::string ASCII_ART = R"(
  ______    ______   ________
 /      \  |      \ |        \
|  $$$$$$\  \$$$$$$  \$$$$$$$$
| $$ __\$$   | $$      | $$
| $$|    \   | $$      | $$
| $$ \$$$$   | $$      | $$
| $$__| $$  _| $$_     | $$
 \$$    $$ |   $$ \    | $$
  \$$$$$$   \$$$$$$     \$$   )";

class Display
{

public:
    void printHelp();
    void printVersion();
    void printUsage();

    void printData(const data::GitData& gitData);
};

}