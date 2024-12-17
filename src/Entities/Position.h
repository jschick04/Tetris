#pragma once

namespace Tetris::Entities
{
    class Position
    {
    public:
        int column;
        int row;

        Position(const int row, const int column) : column(column), row(row) { }
    };
}
