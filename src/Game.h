#pragma once

#include <memory>

#include "Blocks/Blocks.h"
#include "Entities/Grid.h"

namespace Tetris
{
    class Game
    {
    public:
        Game();

        void OnRender();
        void OnUpdate();

    private:
        Entities::Block m_currentBlock;
        std::unique_ptr<Entities::Grid> m_grid;
        Entities::Block m_nextBlock;

        static Entities::Block GetRandomBlock();
    };
}
