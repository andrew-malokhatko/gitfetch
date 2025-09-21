#pragma once

#include <vector>

namespace disp
{

enum class Color
{
    DEFAULT = -1,
    RED = 1,
    GREEN = 2,
    YELLOW = 3,
    BLUE = 4,
    MAGENTA = 5,
    CYAN = 6,
    WHITE = 7,
};

struct Character
{
    char ch{};
    Color color = Color::DEFAULT;
};

class BaseDisplay
{
    int m_xOffset{};
    int m_x{};
    int m_y{};

    Color m_color{};

    std::vector<std::vector<Character>> m_buffer;

public:

    BaseDisplay(int rows, int cols);

    //
    //  set text color in terminal
    //
    void setColor(Color color);

    //
    //
    //
    void setPosition(int x, int y);

    //
    //  prints text at default or previously set position
    //
    void print(const char* text);

    //
    //  dump buffered writes to terminal, it is impossible to edit text that was previously dumped
    //
    void dump();
};

}