#pragma once

#include <vector>

#include "Tetromino.h"

namespace Tetris::Entities
{
    class Grid
    {
    public:
        static constexpr int CellSize = 30;
        static constexpr int Offset = 10;
        static constexpr int Padding = 1;

        [[nodiscard]] bool CanMove(const Tetromino& tetromino) const;
        static Grid Initialize();
        void Lock(const Tetromino& tetromino);
        void Render() const;
        [[nodiscard]] int GetScore() const;
        [[nodiscard]] int GetTotalClears() const;

    private:
        int m_columns = 10;
        std::vector<int> m_grid;
        // TODO: Should be 22, but the top 2 rows are used only for spawn and ending game
        // add solid line above 20th row and only show 21st row
        int m_rows = 20;
        int m_score = 0;
        int m_totalClears = 0;

        Grid() = default;

        void ClearRow(int row);
        int ClearRows();
    };
}
