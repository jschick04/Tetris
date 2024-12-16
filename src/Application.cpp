#include "Application.h"

namespace Tetris
{
    Application::Application(const ApplicationSpecification& spec) : m_spec(spec) { }

    void Application::OnUpdate()
    {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }

    void Application::Run()
    {
        InitWindow(m_spec.Width, m_spec.Height, m_spec.Title.c_str());

        SetTargetFPS(60);

        while (!WindowShouldClose())
        {
            OnUpdate();
        }

        CloseWindow();
    }
}
