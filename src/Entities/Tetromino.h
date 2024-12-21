#pragma once

#include <map>
#include <vector>

#include "Position.h"

namespace Tetris::Entities
{
    class Tetromino
    {
    public:
        int id = 0;
        std::map<int, std::vector<Position>> rotations;

        [[nodiscard]] std::vector<Position> GetPositions() const;
        void Move(int rows, int columns);
        void Render(int offsetX = 0, int offsetY = 0) const;
        void Rotate();
        void UndoRotate();

    private:
        int m_columnOffset = 0;
        int m_rotation = 0;
        int m_rowOffset = 0;
    };
}
