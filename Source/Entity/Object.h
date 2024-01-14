#pragma once
#include <cstddef>
#include <memory>
#include <Component/BoundingBox.h>
#include <Component/Name.h>
#include <Component/Transform.h>
#include <Component/SpriteAnimation.h>
#include "Entity.h"
#include "Tag.h"

namespace Project::Entity
{
    class Object
    {
        bool  m_alive = true;
        const std::size_t m_id = 0;
        const Project::Entity::Tag m_tag = Project::Entity::Tag::DEFAULT;
        
        Object();
        Object(Project::Entity::Tag tag, std::size_t id);
    public:
        friend class Project::Entity::ObjectManager;
        std::shared_ptr<Project::Component::BoundingBox> bounding_box;
        std::shared_ptr<Project::Component::Name>        name;
        std::shared_ptr<Project::Component::Transform>   transform;
        std::shared_ptr<Project::Component::SpriteAnimation> sprite_animation;
        
        void destroy();
        std::size_t get_id() const;
        Project::Entity::Tag get_tag() const;
        bool is_alive() const;
    };
}