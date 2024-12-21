#pragma once

#include <memory>
#include <string>

#include "Game.h"

namespace Tetris
{
    struct ApplicationSpecification
    {
        int Height = 620;
        int Width = 500;
        std::string Title = "Tetris";
    };

    class Application
    {
    public:
        explicit Application(const ApplicationSpecification& spec = ApplicationSpecification());
        Application(const Application&) = delete;
        Application(Application&&) = delete;
        Application& operator=(const Application&) = delete;
        Application& operator=(Application&&) = delete;
        ~Application() noexcept;

        void OnRender() const;
        void OnUpdate() const;
        void Run();

    private:
        Font m_font;
        std::unique_ptr<Game> m_game;
        ApplicationSpecification m_spec;
    };
}
