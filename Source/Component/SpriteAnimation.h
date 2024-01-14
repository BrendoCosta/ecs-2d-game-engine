#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Sprite.h"

namespace Project::Component
{
    struct SpriteAnimation
    {
        std::string name = {};
        std::vector<Project::Component::Sprite> frames;
        std::size_t current_frame = 0;
        float frame_rate = 0.f;
        long last_update = 0;
        bool loop = true;
    };
}