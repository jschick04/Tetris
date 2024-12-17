#pragma once

#include <array>

#include "Block.h"
#include "IBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "OBlock.h"
#include "SBlock.h"
#include "TBlock.h"
#include "ZBlock.h"

namespace Tetris::Entities
{
    inline const std::array<Block, 7> Blocks =
    {
        IBlock(),
        JBlock(),
        LBlock(),
        OBlock(),
        SBlock(),
        TBlock(),
        ZBlock()
    };
}