#pragma once
#include "Vec2.h"

namespace Project::Component
{
    struct BoundingBox
    {
        Project::Component::Vec2<int> size = { 0, 0 };
    };
}