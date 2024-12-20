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

        void OnRender();
        void OnUpdate();
    private:
        std::vector<Entities::Tetromino> m_bag = Entities::Tetrominoes;
        Entities::Tetromino m_current = GetRandomBag();
        std::unique_ptr<Entities::Grid> m_grid = std::make_unique<Entities::Grid>(Entities::Grid::Initialize());
        double m_lastTick = 0;
        Entities::Tetromino m_next = GetRandomBag();
        Entities::Tetromino* m_stashed = nullptr;

        Entities::Tetromino GetRandomBag();
        void HandleInput();
        void MoveDown();
    };
}
