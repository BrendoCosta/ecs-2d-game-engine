#include "Renderer.h"
#include "Image.h"
#include <Component/Sprite.h>

Project::System::Renderer::Renderer()
{
}

void Project::System::Renderer::add_object(std::shared_ptr<Project::Entity::Object> obj)
{
    this->m_objects_waiting_to_be_rendered.push(obj);
}

void Project::System::Renderer::render_sprite(std::shared_ptr<SDL_Renderer> renderer, std::shared_ptr<Project::Entity::Object> obj)
{
    if (!obj || !obj->transform || !obj->sprite_animation || obj->sprite_animation->frames.empty())
    {
        return;
    }
    
    Project::Component::Sprite sprite = obj->sprite_animation->frames[obj->sprite_animation->current_frame];
    
    if (!sprite.surface)
    {
        return;
    }

    SDL_Texture* spritesheet_texture = SDL_CreateTextureFromSurface(renderer.get(), sprite.surface.get());
    SDL_Rect spritesheet_region_to_copy = {
        static_cast<int>(sprite.position.x),
        static_cast<int>(sprite.position.y),
        static_cast<int>(sprite.width),
        static_cast<int>(sprite.height)
    };
    SDL_Rect screen_region_to_draw = {
        static_cast<int>(obj->transform->position.x - (sprite.width * sprite.scale.x) / 2),
        static_cast<int>(obj->transform->position.y - (sprite.height * sprite.scale.y) / 2),
        static_cast<int>(sprite.width * sprite.scale.x),
        static_cast<int>(sprite.height * sprite.scale.y)
    };
    SDL_RenderCopy(renderer.get(), spritesheet_texture, &spritesheet_region_to_copy, &screen_region_to_draw);
    SDL_DestroyTexture(spritesheet_texture);
}

void Project::System::Renderer::render(std::shared_ptr<SDL_Renderer> renderer)
{
    SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 0);
    SDL_RenderClear(renderer.get());
    while (!this->m_objects_waiting_to_be_rendered.empty())
    {
        std::shared_ptr<Project::Entity::Object> obj = this->m_objects_waiting_to_be_rendered.front();
        if (obj)
        {
            if (obj->transform && obj->sprite_animation)
            {
                this->render_sprite(renderer, obj);
            }
            //if (obj->transform)
            //{
            //    SDL_Rect rect = {
            //        (int) obj->transform->position.x - 50 / 2, (int) obj->transform->position.y - 50 / 2,
            //        50, 50
            //    };
            //    //SDL_Rect rect = {
            //    //    (int) obj->transform->position.x, (int) obj->transform->position.y,
            //    //    50, 50
            //    //};
            //    SDL_SetRenderDrawColor(renderer.get(), 255, 255, 255, 255);
            //    SDL_RenderFillRect(renderer.get(), &rect);
            //}
        }
        this->m_objects_waiting_to_be_rendered.pop();
        // ...
    }
    SDL_RenderPresent(renderer.get());
}