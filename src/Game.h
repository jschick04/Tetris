#pragma once

#include <memory>

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
        std::unique_ptr<Entities::Grid> m_grid;
    };
}
