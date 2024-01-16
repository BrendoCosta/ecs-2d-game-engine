#pragma once
#include <memory>
#include <string>
#include <SDL2/SDL.h>

namespace Project::System
{
    class Image
    {
    public:
        static std::shared_ptr<SDL_Surface> load_image(std::string const& path);
    };
}