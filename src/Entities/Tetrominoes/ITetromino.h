#pragma once

#include "Tetromino.h"

namespace Tetris::Entities
{
    class ITetromino : public Tetromino
    {
    public:
        ITetromino()
        {
            id = 1;
            rotations[0] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3) };
            rotations[1] = { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) };
            rotations[2] = { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) };
            rotations[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) };
            Move(-1, 3);
        }
    };
}
