#include "Application.h"

namespace Tetris
{
    Application::Application(const ApplicationSpecification& spec) : m_spec(spec) { }

    void Application::OnRender()
    {
        BeginDrawing();
        ClearBackground(Colors::DarkBlue);

        m_game->OnRender();

        EndDrawing();
    }

    void Application::OnUpdate()
    {
        m_game->OnUpdate();
    }

    void Application::Run()
    {
        InitWindow(m_spec.Width, m_spec.Height, m_spec.Title.c_str());
        SetTargetFPS(60);

        m_game = std::make_unique<Game>();

        while (!WindowShouldClose())
        {
            OnUpdate();
            OnRender();
        }

        CloseWindow();
    }
}
