#pragma once
#include <chrono>
#include <memory>
#include <thread>
#include <SDL2/SDL.h>
#include <Entity/ObjectManager.h>
#include "Renderer.h"

namespace Project::System
{
    class Game
    {
        inline static bool m_initialized;
        std::shared_ptr<SDL_Window> m_window;
        std::shared_ptr<SDL_Renderer> m_renderer;
        Project::System::Renderer m_render_system;
        bool m_running = true;
        bool m_paused = false;
        Project::Entity::ObjectManager m_objectManager;
        void update(float dt);
    public:
        Game();
        void run();
    };
}