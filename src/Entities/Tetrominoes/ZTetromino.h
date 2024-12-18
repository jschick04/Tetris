#pragma once

#include "Tetromino.h"

namespace Tetris::Entities
{
    class ZTetromino : public Tetromino
    {
    public:
        ZTetromino()
        {
            id = 6;
            rotations[0] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) };
            rotations[1] = { Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1) };
            rotations[2] = { Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2) };
            rotations[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0) };
            Move(0, 3);
        }
    };
}
