#pragma once
#include <memory>
#include <queue>
#include <Entity/Object.h>
#include <SDL2/SDL.h>

namespace Project::System
{
    class Renderer
    {
        std::queue<std::shared_ptr<Project::Entity::Object>> m_objects_waiting_to_be_rendered;
        void render_sprite(std::shared_ptr<SDL_Renderer> renderer, std::shared_ptr<Project::Entity::Object> obj);
    public:
        Renderer();
        void add_object(std::shared_ptr<Project::Entity::Object> obj);
        void render(std::shared_ptr<SDL_Renderer> renderer);
    };
}