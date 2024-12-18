#pragma once

#include <array>

namespace Tetris::Colors
{
    inline constexpr Color DarkBlue = { 44, 44, 127, 255 };
    inline constexpr Color DarkGrey = { 26, 31, 40, 255 };
    inline constexpr Color Green = { 47, 230, 23, 255 };
    inline constexpr Color Red = { 232, 18, 18, 255 };
    inline constexpr Color Orange = { 226, 116, 17, 255 };
    inline constexpr Color Yellow = { 237, 234, 4, 255 };
    inline constexpr Color Purple = { 166, 0, 247, 255 };
    inline constexpr Color Cyan = { 21, 204, 209, 255 };
    inline constexpr Color Blue = { 13, 64, 216, 255 };

    inline constexpr std::array BlockColors = { DarkGrey, Cyan, Blue, Orange, Yellow, Green, Red, Purple };
}
