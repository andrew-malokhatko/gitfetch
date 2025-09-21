#include "disp/BaseDisplay.hpp"

#include <iostream>

namespace disp
{

BaseDisplay::BaseDisplay(int rows, int cols)
{
    m_buffer = std::vector<std::vector<Character>>(rows, std::vector<Character>(cols));

    for (auto& row : m_buffer)
    {
        std::fill(row.begin(), row.end(), Character(' ', Color::DEFAULT));
    }
}

void BaseDisplay::setColor(Color color)
{
    m_color = color;
}

void BaseDisplay::setPosition(int x, int y)
{
    m_xOffset = x;
    m_x = x;
    m_y = y;
}

void BaseDisplay::print(const char* text)
{
    if (m_buffer.empty() || m_buffer[0].empty())
    {
        return;
    }

    int rows = m_buffer.size();
    int cols = m_buffer[0].size();

    while (*text)
    {
        if (*text == '\n')
        {
            m_x = m_xOffset;
            m_y++;
        }
        else if (m_x >= 0 && m_y >= 0 &&
                m_y < rows && m_x < cols)
        {
            m_buffer[m_y][m_x] = {*text, m_color};
            m_x++;
        }

        text++;
    }
}

void outputColor(Color color)
{
    if (color == Color::DEFAULT)
    {
        std::cout << "\033[0m";
        return;
    }

    int code = static_cast<int>(color) + 30;

    std::cout << "\033[" << code << "m";
}

void BaseDisplay::dump()
{
    if (m_buffer.empty() || m_buffer[0].empty())
    {
        return;
    }

    Color curColor = Color::DEFAULT;

    for (size_t row = 0, rows = m_buffer.size(); row < rows; row++)
    {
        for (size_t col = 0, cols = m_buffer[row].size(); col < cols; col++)
        {
            const Character& curChar = m_buffer[row][col];

            if (curColor != curChar.color)
            {
                curColor = curChar.color;
                outputColor(curColor);
            }

            std::cout << curChar.ch;
        }

        std::cout << "\n";
    }
}

}