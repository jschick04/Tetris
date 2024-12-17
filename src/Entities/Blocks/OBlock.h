#include "Block.h"

namespace Tetris::Entities
{
    class OBlock : public Block
    {
    public:
       OBlock()
        {
            id = 4;
            rotations[0] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) };
            Move(0, 4);
        }
    };
}
