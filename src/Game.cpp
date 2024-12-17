#include "Game.h"

namespace Tetris
{
    Game::Game()
    {
        m_grid = std::make_unique<Entities::Grid>(Entities::Grid::Initialize());
    }

    void Game::OnRender()
    {
        m_grid->Render();
    }

    void Game::OnUpdate() { }
}
