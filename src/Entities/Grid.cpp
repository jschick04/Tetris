#include "Grid.h"

#include <vector>

namespace Tetris::Entities
{
    bool Grid::CanMove(Tetromino& tetromino) const
    {
        for (const auto& position : tetromino.GetPositions())
        {
            if (position.row < 0 || position.row >= m_rows || position.column < 0 || position.column >= m_columns)
            {
                return false;
            }

            if (m_grid[position.row][position.column] != 0)
            {
                return false;
            }
        }

        return true;
    }

    Grid Grid::Initialize()
    {
        Grid grid;

        grid.m_grid = std::vector(grid.m_rows, std::vector(grid.m_columns, 0));

        return grid;
    }

    void Grid::Lock(Tetromino& tetromino)
    {
        for (const auto& position : tetromino.GetPositions())
        {
            m_grid[position.row][position.column] = tetromino.id;
        }

        ClearRows();
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
                    Colors::BlockColors[m_grid[row][column]]);
            }
        }
    }

    void Grid::ClearRow(const int row)
    {
        for (int currentRow = row; currentRow > 0; currentRow--)
        {
            for (int column = 0; column < m_columns; column++)
            {
                m_grid[currentRow][column] = m_grid[currentRow - 1][column];
                m_grid[0][column] = 0;
            }
        }
    }

    int Grid::ClearRows()
    {
        int clearedRows = 0;

        for (int row = 0; row <= m_rows - 1; row++)
        {
            bool isRowFull = true;

            for (int column = 0; column < m_columns; column++)
            {
                if (m_grid[row][column] == 0)
                {
                    isRowFull = false;

                    break;
                }
            }

            if (isRowFull)
            {
                ClearRow(row);

                clearedRows++;
            }
        }

        return clearedRows;
    }
}
