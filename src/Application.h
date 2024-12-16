#pragma once

#include <string>

namespace Tetris
{
    struct ApplicationSpecification
    {
        int Height = 1000;
        int Width = 1000;
        std::string Title = "Tetris";
    };

    class Application
    {
    public:
        explicit Application(const ApplicationSpecification& spec = ApplicationSpecification());

        void OnUpdate();
        void Run();

    private:
        ApplicationSpecification m_spec;
    };
}
