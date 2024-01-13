#include "Movement.h"

void Project::System::Movement::linear_move(std::shared_ptr<Project::Entity::Object> obj, Project::Component::Vec2f target_position)
{
    if (!obj->transform)
    {
        return;
    }
    else
    {
        if (obj->transform->position != target_position)
        {
            Project::Component::Vec2<float> direction = target_position - obj->transform->position;
            //obj.transform->position += direction.clamp_magnitude((25.f/100.f)/1.f * dt);
            obj->transform->position += direction.normalized() * obj->transform->velocity.clamp_magnitude(direction.length());
        }
    }
}