#include <iostream>
#include <string>
#include <string_view>

#include "disp/Display.hpp"
#include "parse/Parser.hpp"

static disp::Display display{};

struct Args
{
    bool all{};
};

Args parseArgs(int argc, char* argv[])
{
    Args args{};

    for (int i = 1; i < argc; i++)
    {
        const std::string_view arg{argv[i]};

        // help
        if (arg == "-h" || arg == "--help")
        {
            display.printHelp();
            std::exit(0);
        }

        // version
        if (arg == "-v" || arg == "--version")
        {

            std::exit(0);
        }

        // options
        if (arg == "-a" || arg == "--all")
        {
            args.all = true;
        }

        // unknown
        else
        {
            std::cerr << "Unknown argument " << arg << "\n";
            std::cerr << "Type '--help' to see the usage\n";
            std::exit(1);
        }
    }

    return args;
}

int main(int argc, char* argv[])
{
    Args args = parseArgs(argc, argv);

    // TODO: change to an input parameter
    static const std::string_view repositoryPath = "/home/andr/Programming/C++/concurrency";

    // extract data from the git repo
    data::GitData gitData{};

    try
    {
        parse::Parser parser{repositoryPath};
        gitData = parser.getData();
    }
    catch (std::runtime_error& e)
    {
        std::cerr << e.what() << "\n";
        std::cerr << "Type '--help' to see the usage\n";
        std::exit(1);
    }

    display.printData(gitData);

    return 0;
}