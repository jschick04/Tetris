#include "Game.h"

#include <algorithm>
#include <random>

namespace Tetris
{
    Game::Game()
    {
        m_grid = std::make_unique<Entities::Grid>(Entities::Grid::Initialize());
        m_current = GetRandomBag();
        m_next = GetRandomBag();
    }

    void Game::OnRender()
    {
        m_grid->Render();
        m_current.Render();
    }

    void Game::OnUpdate()
    {
        if (const double currentTick = GetTime(); currentTick - m_lastTick >= 0.2)
        {
            MoveDown();
            m_lastTick = currentTick;
        }

        switch (GetKeyPressed())
        {
            case KEY_LEFT:
                m_current.Move(0, -1);

                if (!m_grid->CanMove(m_current))
                {
                    m_current.Move(0, 1);
                }

                break;
            case KEY_RIGHT:
                m_current.Move(0, 1);

                if (!m_grid->CanMove(m_current))
                {
                    m_current.Move(0, -1);
                }

                break;
            case KEY_SPACE:
            // Slam down
            case KEY_DOWN:
                MoveDown();

                break;
            case KEY_UP:
                m_current.Rotate();

                if (!m_grid->CanMove(m_current))
                {
                    m_current.UndoRotate();
                }

                break;
            case KEY_LEFT_SHIFT:
            case KEY_C:
                // Hold
                break;
            case KEY_LEFT_CONTROL:
            case KEY_Z:
                m_current.UndoRotate();

                if (!m_grid->CanMove(m_current))
                {
                    m_current.Rotate();
                }

                break;
        }
    }

    Entities::Tetromino Game::GetRandomBag()
    {
        if (m_bag.empty())
        {
            m_bag = Entities::Tetrominoes;
        }

        std::random_device rd;
        std::mt19937 generator(rd());
        std::ranges::shuffle(m_bag, generator);
        const Entities::Tetromino tetromino = m_bag.back();
        m_bag.pop_back();

        return tetromino;
    }

    void Game::MoveDown()
    {
        m_current.Move(1, 0);

        if (!m_grid->CanMove(m_current))
        {
            m_current.Move(-1, 0);

            // Needs to be a 0.5s delay before the next block spawns where the player can still move the block left and right
            m_grid->Lock(m_current);
            m_current = m_next;
            m_next = GetRandomBag();
        }
    }
}
