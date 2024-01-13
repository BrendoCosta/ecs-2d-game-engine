#pragma once
#include "Vec2.h"

namespace Project::Component
{
    struct Transform
    {
        Project::Component::Vec2<float> position          = { 0, 0 };
        Project::Component::Vec2<float> previous_position = { 0, 0 };
        Project::Component::Vec2<float> velocity          = { 0.0f, 0.0f };
        Project::Component::Vec2<float> scale             = { 0.0f, 0.0f };
        float                           angle             = 0.0f;
    };
}