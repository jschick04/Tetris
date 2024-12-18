#pragma once

#include "Tetromino.h"

namespace Tetris::Entities
{
    class OTetromino : public Tetromino
    {
    public:
       OTetromino()
        {
            id = 4;
            rotations[0] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
            Move(0, 4);
        }
    };
}
