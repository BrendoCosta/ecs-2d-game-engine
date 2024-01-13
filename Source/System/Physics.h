#pragma once
#include <Entity/Object.h>

namespace Project::System
{
    class Physics
    {
    public:
        static bool check_collision(Project::Entity::Object const& a, Project::Entity::Object const& b);
        static bool check_collision_centered(Project::Entity::Object const& a, Project::Entity::Object const& b);
    };
}