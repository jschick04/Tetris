#pragma once

#include <array>

namespace Tetris::Colors
{
    inline constexpr Color DarkGrey = { 26, 31, 40, 255 };
    inline constexpr Color Green = { 66, 182, 66, 255 };
    inline constexpr Color Red = { 238, 32, 40, 255 };
    inline constexpr Color Orange = { 238, 120, 32, 255 };
    inline constexpr Color Yellow = { 247, 211, 8, 255 };
    inline constexpr Color Purple = { 173, 77, 156, 255 };
    inline constexpr Color DarkBlue = { 13, 71, 161, 255 };
    inline constexpr Color Cyan = { 49, 199, 239, 255 };
    inline constexpr Color Blue = { 90, 101, 173, 255 };
    inline constexpr Color White = { 255, 255, 255, 255 };

    inline constexpr std::array BlockColors = { DarkGrey, Cyan, Blue, Orange, Yellow, Green, Red, Purple };
}
