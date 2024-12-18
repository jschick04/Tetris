#pragma once

#include <vector>

#include "Tetromino.h"

namespace Tetris::Entities
{
    class Grid
    {
    public:
        [[nodiscard]] bool CanMove(Tetromino& tetromino) const;
        static Grid Initialize();
        void Lock(Tetromino& tetromino);
        void Render() const;

    private:
        int m_cellSize = 30;
        int m_columns = 10;
        std::vector<std::vector<int>> m_grid;
        int m_rows = 20; // Should be 22, but the top 2 rows are used only for spawn and ending game, add solid line above 20th row and only show 21st row

        void ClearRow(int row);
        int ClearRows();
    };
}
