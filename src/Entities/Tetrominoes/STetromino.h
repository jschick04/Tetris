#pragma once

#include "Tetromino.h"

namespace Tetris::Entities
{
    class STetromino : public Tetromino
    {
    public:
        STetromino()
        {
            id = 5;
            rotations[0] = { Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1) };
            rotations[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2) };
            rotations[2] = { Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1) };
            rotations[3] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1) };
            Move(0, 3);
        }
    };
}
