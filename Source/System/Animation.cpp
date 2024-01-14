#include "Animation.h"
#include <SDL2/SDL.h>
#include <Component/Sprite.h>

void Project::System::Animation::update(std::shared_ptr<Project::Entity::Object> obj)
{
    if (!obj || !obj->sprite_animation || obj->sprite_animation->frames.empty())
    {
        return;
    }

    float duration = 0.f;

    if (obj->sprite_animation->frame_rate != 0.f)
    {
        duration = 1000.f / obj->sprite_animation->frame_rate;
    }
    else
    {
        duration = obj->sprite_animation->frames[obj->sprite_animation->current_frame].duration;
    }

    if (SDL_GetTicks64() - obj->sprite_animation->last_update > duration)
    {
        if (!obj->sprite_animation->loop && obj->sprite_animation->current_frame == obj->sprite_animation->frames.size() - 1)
        {
            return;
        }
        obj->sprite_animation->current_frame = (obj->sprite_animation->current_frame + 1) % obj->sprite_animation->frames.size();
        obj->sprite_animation->last_update = SDL_GetTicks64();
    }
}