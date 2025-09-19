#include "../Display.h"

#include <iostream>

#define DEFAULT "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

namespace disp
{
    void Display::printHelp()
    {
        std::cout << "HELP\n";
    }

    void Display::printVersion()
    {
        std::cout << "version: " << "\n";
    }

    void Display::printUsage()
    {
        std::cout << "usage: 'gitfetch <path>'\n";
    }

    void Display::printData(const GitData& gitData)
    {
        std::cout << defaultAsciiArt << "\n";

        // print name
        std::cout << BLUE << gitData.user << DEFAULT << "@" << BLUE << gitData.name << DEFAULT << "\n";

        // print delim string
        size_t delimSize = gitData.name.size() + gitData.user.size() + 1;
        std::string delimStr(delimSize, '-');
        std::cout << delimStr << "\n";

        // print stats
        std::cout << BLUE << "Branch: " << DEFAULT << gitData.branch << "\n";
        std::cout << BLUE << "Remote: " << DEFAULT << gitData.remote << "\n";
        std::cout << BLUE << "Commits: " << DEFAULT << gitData.commitCount << "\n";
        std::cout << BLUE << "Message: " << DEFAULT << gitData.commit.message << "\n";
        std::cout << BLUE << "Author: " << DEFAULT << gitData.commit.author << "\n";
        std::cout << BLUE << "Contact: " << DEFAULT << gitData.commit.email << "\n";
    }

}  // namespace disp