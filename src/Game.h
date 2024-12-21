#pragma once

#include <memory>

#include "Grid.h"
#include "Tetrominoes/Tetrominoes.h"

namespace Tetris
{
    class Game
    {
    public:
        [[nodiscard]] int GetScore() const;
        [[nodiscard]] bool IsGameOver() const;
        void OnRender() const;
        void OnUpdate();

    private:
        std::vector<Entities::Tetromino> m_bag = Entities::Tetrominoes;
        Entities::Tetromino m_current = GetRandomBag();
        bool m_isGameOver = false;
        double m_lastTick = 0;
        std::unique_ptr<Entities::Grid> m_grid = std::make_unique<Entities::Grid>(Entities::Grid::Initialize());
        Entities::Tetromino m_next = GetRandomBag();
        Entities::Tetromino* m_stashed = nullptr;

        Entities::Tetromino GetRandomBag();
        void HandleInput();
        void MoveDown();
    };
}
