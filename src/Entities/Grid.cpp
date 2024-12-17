#include "Grid.h"

#include <iostream>
#include <vector>

namespace Tetris::Entities
{
    Grid Grid::Initialize()
    {
        Grid grid;

        grid.m_grid = std::vector(grid.m_rows, std::vector(grid.m_columns, 0));

        return grid;
    }

    void Grid::Render() const
    {
        for (int row = 0; row < m_rows; row++)
        {
            for (int column = 0; column < m_columns; column++)
            {
                DrawRectangle(
                    column * m_cellSize + 1,
                    row * m_cellSize + 1,
                    m_cellSize - 1,
                    m_cellSize - 1,
                    m_colors[m_grid[row][column]]);
            }
        }
    }
}
