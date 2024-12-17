#pragma once
#include <vector>

namespace Tetris::Entities
{
    class Grid
    {
    public:
        static Grid Initialize();
        void Render() const;

    private:
        int m_cellSize = 30;
        std::vector<Color> m_colors =
        {
            Colors::DarkGrey,
            Colors::Green,
            Colors::Red,
            Colors::Orange,
            Colors::Yellow,
            Colors::Purple,
            Colors::Cyan,
            Colors::Blue,
        };
        int m_columns = 10;
        std::vector<std::vector<int>> m_grid;
        int m_rows = 20;
    };
}
