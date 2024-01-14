#include <iostream>
#include <SDL2/SDL.h>
#include <Component/Vec2.h>
#include <Component/Sprite.h>
#include <Component/SpriteAnimation.h>
#include "Game.h"
#include "Movement.h"
#include "Renderer.h"
#include "Animation.h"

Project::System::Game::Game()
{
    if (!Project::System::Game::m_initialized)
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        this->m_window = std::shared_ptr<SDL_Window>(SDL_CreateWindow("Game", 0, 0, 640, 480, SDL_WINDOW_RESIZABLE), [](SDL_Window* ptr) { SDL_DestroyWindow(ptr); });
        this->m_renderer = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(this->m_window.get(), -1, SDL_RENDERER_ACCELERATED), [](SDL_Renderer* ptr) { SDL_DestroyRenderer(ptr); });

        std::shared_ptr<Project::Entity::Object> obj = this->m_objectManager.add_object(Project::Entity::Tag::DEFAULT);
        obj->name = std::make_shared<Project::Component::Name>("Test");
        obj->transform = std::make_shared<Project::Component::Transform>(Project::Component::Transform {});
        obj->transform->position.x = 640/2 - 150;
        obj->transform->position.y = 480/2 - 150;
        obj->sprite_animation = std::make_shared<Project::Component::SpriteAnimation>();
        //obj->sprite_animation->frame_rate = 3.f;
        //obj->sprite_animation->loop = false;
        obj->sprite_animation->frames.push_back(
            {
                nullptr,
                { 0.f, 0.f },
                0,
                0,
                300.f
            }
        );
        obj->sprite_animation->frames.push_back(
            {
                nullptr,
                { 0.f, 0.f },
                0,
                0,
                1000.f
            }
        );
        obj->sprite_animation->frames.push_back(
            {
                nullptr,
                { 0.f, 0.f },
                0,
                0,
                300.f
            }
        );
    }
}

void Project::System::Game::update(float dt)
{
    if (!this->m_paused)
    {
        this->m_objectManager.update();
        //sUserInput();
        //sMovement();
        //sCollision();
    }
    for (auto obj : this->m_objectManager.get_objects())
    {
        if (obj->transform)
        {
            Project::Component::Vec2<float> target = { 500.0f, 400.0f };
            if (obj->transform->position != target)
            {
                obj->transform->velocity.x = (25.f/100.f)/1.f * dt;
                obj->transform->velocity.y = (12.5f/100.f)/1.f * dt;
                Project::System::Movement::linear_move(obj, target);
                //Project::Component::Vec2<float> direction = target - obj->transform->position;
                //obj->transform->position += direction.clamp_magnitude((25.f/100.f)/1.f * dt);
            }
            //obj->transform->position.rotate((25.f/100.f)/1.f * dt, Project::Component::Vec2(640/2, 480/2));
        }
        Project::System::Animation::update(obj);
        this->m_render_system.add_object(obj);
    }
    this->m_render_system.render(this->m_renderer);
}

void Project::System::Game::run()
{
    long last_update = SDL_GetTicks64();
    while (this->m_running)
    {
        long delta = SDL_GetTicks64() - last_update;
        last_update = SDL_GetTicks64();
        this->update(delta);
        float elapsed_ms = SDL_GetTicks64() - last_update;
        float fps_limit = 60.0f;
        if (elapsed_ms < (1000.0f / fps_limit))
        {
            SDL_Delay(std::floor((1000.0f / fps_limit) - elapsed_ms));
        }
    }
}