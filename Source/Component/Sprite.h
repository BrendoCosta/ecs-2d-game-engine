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
        std::size_t width = 0;
        std::size_t height = 0;
        float duration = 0.f;
    };
}