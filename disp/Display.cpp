#include "Display.hpp"

#include "disp/BaseDisplay.hpp"

namespace disp
{

void Display::printHelp()
{
    BaseDisplay bd = BaseDisplay(20, 100);
    bd.print("version: 0.1\n");
    bd.dump();
}

void Display::printVersion()
{
    BaseDisplay bd = BaseDisplay(20, 100);
    bd.print("version: 0.1\n");
    bd.dump();
}

void Display::printUsage()
{
    BaseDisplay bd = BaseDisplay(20, 100);
    bd.print("usage: 'gitfetch <path>'\n");
    bd.dump();
}

void Display::printData(const data::GitData& gitData)
{
    BaseDisplay bd = BaseDisplay(20, 100);

    auto printStat = [&bd](const char* statName, const char* statValue) -> void
    {
        bd.setColor(Color::BLUE);
        bd.print(statName);
        bd.setColor(Color::WHITE);
        bd.print(statValue);
        bd.print("\n");
    };

    bd.setColor(Color::WHITE);
    bd.print(ASCII_ART.c_str());

    bd.setPosition(40, 2);

    // print name
    bd.setColor(Color::BLUE);
    bd.print(gitData.user.c_str());
    bd.setColor(Color::WHITE);
    bd.print("@");
    bd.setColor(Color::BLUE);
    bd.print(gitData.name.c_str());
    bd.print("\n");

    std::string commitCount = std::to_string(gitData.commitCount);

    // print other stats
    printStat("Branch: ", gitData.branch.c_str());
    printStat("Remote: ", gitData.remote.c_str());
    printStat("Commits: ", commitCount.c_str());
    printStat("Message: ", gitData.commit.message.c_str());
    printStat("Author: ", gitData.commit.author.c_str());
    printStat("Last updated: ", gitData.commit.date.c_str());

    bd.dump();
}

}