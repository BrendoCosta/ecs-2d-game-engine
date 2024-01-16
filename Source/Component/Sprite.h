#pragma once
#include <memory>
#include <SDL2/SDL.h>
#include "Vec2.h"

namespace Project::Component
{
    struct Sprite
    {
        std::shared_ptr<SDL_Surface> surface = nullptr;
        Project::Component::Vec2f position = { 0.f, 0.f };
        float width = 0.f;
        float height = 0.f;
        Project::Component::Vec2f scale = { 1.f, 1.f };
        float duration = 0.f;
    };
}