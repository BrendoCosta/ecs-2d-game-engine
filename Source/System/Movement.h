#pragma once
#include <memory>
#include <Component/Vec2.h>
#include <Entity/Object.h>

namespace Project::System
{
    class Movement
    {
    public:
        static void linear_move(std::shared_ptr<Project::Entity::Object> obj, Project::Component::Vec2f target_position);
    };
}