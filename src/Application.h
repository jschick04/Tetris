#pragma once

#include <memory>
#include <string>

#include "Game.h"

namespace Tetris
{
    struct ApplicationSpecification
    {
        int Height = 600;
        int Width = 300;
        std::string Title = "Tetris";
    };

    class Application
    {
    public:
        explicit Application(const ApplicationSpecification& spec = ApplicationSpecification());

        void OnRender();
        void OnUpdate();
        void Run();

    private:
        std::unique_ptr<Game> m_game;
        ApplicationSpecification m_spec;
    };
}
