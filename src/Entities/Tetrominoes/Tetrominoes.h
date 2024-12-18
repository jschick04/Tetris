#pragma once

#include <vector>

#include "ITetromino.h"
#include "JTetromino.h"
#include "LTetromino.h"
#include "OTetromino.h"
#include "STetromino.h"
#include "TTetromino.h"
#include "Tetromino.h"
#include "ZTetromino.h"

namespace Tetris::Entities
{
    inline const std::vector<Tetromino> Tetrominoes =
    {
        ITetromino(),
        JTetromino(),
        LTetromino(),
        OTetromino(),
        STetromino(),
        TTetromino(),
        ZTetromino()
    };
}
