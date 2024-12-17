#include "Block.h"

namespace Tetris::Entities
{
    class IBlock : public Block
    {
    public:
        IBlock()
        {
            id = 1;
            rotations[0] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) };
            rotations[1] = { Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1) };
            rotations[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) };
            rotations[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 1) };
            Move(-1, 3);
        }
    };
}