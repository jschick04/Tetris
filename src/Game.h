#pragma once

#include <memory>

#include "Entities/Grid.h"
#include "Tetrominoes/Tetrominoes.h"

namespace Tetris
{
    class Game
    {
    public:
        // 40 - Single
        // 100 - Double
        // 300 - Triple
        // 1200 - Tetris
        int score = 0;

        Game();

        void OnRender();
        void OnUpdate();

    private:
        std::vector<Entities::Tetromino> m_bag = Entities::Tetrominoes;
        Entities::Tetromino m_current;
        std::unique_ptr<Entities::Grid> m_grid;
        double m_lastTick = 0;
        Entities::Tetromino m_next;

        Entities::Tetromino GetRandomBag();
        void MoveDown();
    };
}
