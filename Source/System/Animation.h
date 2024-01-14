#pragma once
#include <memory>
#include <Entity/Object.h>

namespace Project::System
{
    class Animation
    {
    public:
        static void update(std::shared_ptr<Project::Entity::Object> obj);
    };
}