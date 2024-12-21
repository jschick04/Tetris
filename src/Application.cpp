#include "Application.h"

namespace Tetris
{
    // ReSharper disable once CppPossiblyUninitializedMember
    // m_font has to be initialized after InitWindow
    Application::Application(const ApplicationSpecification& spec) : m_spec(spec) { }

    Application::~Application() noexcept
    {
        UnloadFont(m_font);
    }

    void Application::OnRender() const
    {
        BeginDrawing();
        ClearBackground(Colors::DarkBlue);

        DrawTextEx(m_font, "Score", { 340, 15 }, 38, 2, Colors::White);
        DrawRectangleRounded({ 320, 55, 170, 60 }, 0.2f, 6, Colors::DarkGrey);

        const std::string score = std::to_string(m_game->GetScore());
        const auto [x, y] = MeasureTextEx(m_font, score.c_str(), 38, 2);
        const Vector2 scorePosition = { 320 + (170 - x) / 2, 70 };

        DrawTextEx(m_font, score.c_str(), scorePosition, 38, 2, Colors::White);

        DrawTextEx(m_font, "Next", { 350, 125 }, 38, 2, Colors::White);
        DrawRectangleRounded({ 320, 165, 170, 160 }, 0.2f, 6, Colors::DarkGrey);

        DrawTextEx(m_font, "Hold", { 350, 335 }, 38, 2, Colors::White);
        DrawRectangleRounded({ 320, 375, 170, 160 }, 0.2f, 6, Colors::DarkGrey);

        m_game->OnRender();

        if (m_game->IsGameOver())
        {
            DrawTextEx(m_font, "GAME OVER", { 100, 200 }, 46, 2, Colors::White);
        }

        EndDrawing();
    }

    void Application::OnUpdate() const
    {
        m_game->OnUpdate();
    }

    void Application::Run()
    {
        InitWindow(m_spec.Width, m_spec.Height, m_spec.Title.c_str());
        SetTargetFPS(60);

        m_font = LoadFontEx("res/fonts/Tetris.ttf", 64, nullptr, 0);
        m_game = std::make_unique<Game>();

        while (!WindowShouldClose())
        {
            OnUpdate();
            OnRender();
        }

        CloseWindow();
    }
}
