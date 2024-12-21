#include "Grid.h"

#include <vector>

namespace Tetris::Entities
{
    bool Grid::CanMove(const Tetromino& tetromino) const
    {
        for (const auto& position : tetromino.GetPositions())
        {
            if (position.row < 0 || position.row >= m_rows || position.column < 0 || position.column >= m_columns)
            {
                return false;
            }

            if (m_grid[position.row * m_columns + position.column] != 0)
            {
                return false;
            }
        }

        return true;
    }

    Grid Grid::Initialize()
    {
        Grid grid;

        grid.m_grid.resize(grid.m_rows * grid.m_columns, 0);

        return grid;
    }

    void Grid::Lock(const Tetromino& tetromino)
    {
        for (const auto& position : tetromino.GetPositions())
        {
            m_grid[position.row * m_columns + position.column] = tetromino.id;
        }

        const int rowsCleared = ClearRows();

        switch (rowsCleared)
        {
            case 1:
                m_score += 40;
                break;
            case 2:
                m_score += 100;
                break;
            case 3:
                m_score += 300;
                break;
            case 4:
                m_score += 1200;
                break;
        }

        m_totalClears += rowsCleared;
    }

    void Grid::Render() const
    {
        for (int row = 0; row < m_rows; row++)
        {
            for (int column = 0; column < m_columns; column++)
            {
                DrawRectangle(
                    column * CellSize + Offset + Padding,
                    row * CellSize + Offset + Padding,
                    CellSize - Padding,
                    CellSize - Padding,
                    Colors::BlockColors[m_grid[row * m_columns + column]]);
            }
        }
    }

    int Grid::GetScore() const { return m_score; }

    int Grid::GetTotalClears() const { return m_totalClears; }

    void Grid::ClearRow(const int row)
    {
        for (int currentRow = row; currentRow > 0; currentRow--)
        {
            for (int column = 0; column < m_columns; column++)
            {
                m_grid[currentRow * m_columns + column] = m_grid[(currentRow - 1) * m_columns + column];
                m_grid[column] = 0;
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
                if (m_grid[row * m_columns + column] == 0)
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
