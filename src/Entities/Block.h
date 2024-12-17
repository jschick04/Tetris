#pragma once

#include <map>
#include <vector>

#include "Position.h"

namespace Tetris::Entities
{
    class Block
    {
    public:
        int id;
        std::map<int, std::vector<Position>> rotations;

        [[nodiscard]] std::vector<Position> GetPositions();
        void Move(int rows, int columns);
        void Render();
        void Rotate();
        void UndoRotate();

    private:
        int m_cellSize = 30;
        int m_columnOffset = 0;
        int m_rotation = 0;
        int m_rowOffset = 0;
    };
}
