#include "Tetromino.h"

namespace Tetris::Entities
{
    std::vector<Position> Tetromino::GetPositions()
    {
        const std::vector<Position>& positions = rotations[m_rotation];
        std::vector<Position> updatedPositions;

        updatedPositions.reserve(positions.size());

        for (const Position position : positions)
        {
            updatedPositions.emplace_back(position.row + m_rowOffset, position.column + m_columnOffset);
        }

        return updatedPositions;
    }

    void Tetromino::Move(const int rows, const int columns)
    {
        m_rowOffset += rows;
        m_columnOffset += columns;
    }

    void Tetromino::Render()
    {
        for (const Position& position : GetPositions())
        {
            DrawRectangle(
                position.column * m_cellSize + 11,
                position.row * m_cellSize + 11,
                m_cellSize - 1,
                m_cellSize - 1,
                Colors::BlockColors[id]);
        }
    }

    void Tetromino::Rotate() { m_rotation = (m_rotation + 1) % static_cast<int>(rotations.size()); }

    void Tetromino::UndoRotate()
    {
        m_rotation = (m_rotation + (static_cast<int>(rotations.size()) - 1)) % static_cast<int>(rotations.size());
    }
}
