#include "Physics.h"

bool Project::System::Physics::check_collision(Project::Entity::Object const& a, Project::Entity::Object const& b)
{
    if (a.transform && b.transform && a.bounding_box && b.bounding_box)
    {
        bool horizontal_overlap = a.transform->position.x < b.transform->position.x + b.bounding_box->size.x &&
                                  b.transform->position.x < a.transform->position.x + a.bounding_box->size.x;
        bool vertical_overlap   = a.transform->position.y < b.transform->position.y + b.bounding_box->size.y &&
                                  b.transform->position.y < a.transform->position.y + a.bounding_box->size.y;
        return horizontal_overlap && vertical_overlap;
    }
    return false;
}

bool Project::System::Physics::check_collision_centered(Project::Entity::Object const& a, Project::Entity::Object const& b)
{
    if (a.transform && b.transform && a.bounding_box && b.bounding_box)
    {
        int delta_x   = std::abs(a.transform->position.x - b.transform->position.x);
        int delta_y   = std::abs(a.transform->position.y - b.transform->position.y);
        int overlap_x = (a.bounding_box->size.x / 2) + (b.bounding_box->size.x / 2) - delta_x;
        int overlap_y = (a.bounding_box->size.y / 2) + (b.bounding_box->size.y / 2) - delta_y;
        return overlap_x > 0 && overlap_y > 0;
    }
    return false;
}