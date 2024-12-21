#include "Tetromino.h"

#include "Grid.h"

namespace Tetris::Entities
{
    std::vector<Position> Tetromino::GetPositions() const
    {
        const std::vector<Position>& positions = rotations.at(m_rotation);
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

    void Tetromino::Render(const int offsetX, const int offsetY) const
    {
        for (const Position& position : GetPositions())
        {
            DrawRectangle(
                position.column * Grid::CellSize + Grid::Offset + Grid::Padding + offsetX,
                position.row * Grid::CellSize + Grid::Offset + Grid::Padding + offsetY,
                Grid::CellSize - Grid::Padding,
                Grid::CellSize - Grid::Padding,
                Colors::BlockColors[id]);
        }
    }

    void Tetromino::Rotate() { m_rotation = (m_rotation + 1) % static_cast<int>(rotations.size()); }

    void Tetromino::UndoRotate()
    {
        m_rotation = (m_rotation + (static_cast<int>(rotations.size()) - 1)) % static_cast<int>(rotations.size());
    }
}
