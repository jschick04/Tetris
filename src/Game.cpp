#include "Game.h"

namespace Tetris
{
    Game::Game()
    {
        m_grid = std::make_unique<Entities::Grid>(Entities::Grid::Initialize());
        m_currentBlock = GetRandomBlock();
        m_nextBlock = GetRandomBlock();
    }

    void Game::OnRender()
    {
        m_grid->Render();
        m_currentBlock.Render();
    }

    void Game::OnUpdate() { }

    Entities::Block Game::GetRandomBlock()
    {
        const int index = rand() % Entities::Blocks.size();
        const Entities::Block& block = Entities::Blocks[index];
        return block;
    }
}
