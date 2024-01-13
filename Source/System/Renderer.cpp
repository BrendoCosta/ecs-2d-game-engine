#include "Renderer.h"

Project::System::Renderer::Renderer()
{ 
}

void Project::System::Renderer::add_object(std::shared_ptr<Project::Entity::Object> obj)
{
    this->m_objects_waiting_to_be_rendered.push(obj);
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
            if (obj->transform)
            {
                SDL_Rect rect = {
                    (int) obj->transform->position.x - 50 / 2, (int) obj->transform->position.y - 50 / 2,
                    50, 50
                };
                //SDL_Rect rect = {
                //    (int) obj->transform->position.x, (int) obj->transform->position.y,
                //    50, 50
                //};
                SDL_SetRenderDrawColor(renderer.get(), 255, 255, 255, 255);
                SDL_RenderFillRect(renderer.get(), &rect);
            }
        }
        this->m_objects_waiting_to_be_rendered.pop();
        // ...
    }
    SDL_RenderPresent(renderer.get());
}