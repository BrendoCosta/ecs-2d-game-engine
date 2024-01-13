#pragma once
#include <cstddef>
#include <map>
#include <memory>
#include <queue>
#include <vector>
#include "Entity.h"
#include "Object.h"
#include "Tag.h"

namespace Project::Entity
{
    using ObjectVector = std::vector<std::shared_ptr<Project::Entity::Object>>;
    using ObjectMap    = std::map<Project::Entity::Tag, ObjectVector>;
    using ObjectQueue  = std::queue<std::shared_ptr<Project::Entity::Object>>;
    
    class ObjectManager
    {
        Project::Entity::ObjectVector m_objects;
        Project::Entity::ObjectQueue  m_objects_waiting_to_be_added;
        Project::Entity::ObjectMap    m_objectsMap;
        std::size_t                   m_total_objects_so_far = 0;
    public:
        ObjectManager();
        
        /// @fn 
        /// @brief  Adds a new object to the queue of objects waiting to be added.
        std::shared_ptr<Project::Entity::Object> add_object(Project::Entity::Tag tag);
        
        /// @fn 
        /// @brief  Returns all objects managed by the instance.
        Project::Entity::ObjectVector& get_objects();

        /// @fn 
        /// @brief  Returns all objects with the given tag managed by the instance.
        Project::Entity::ObjectVector& get_objects_by_tag(Project::Entity::Tag tag);
        
        /// @fn 
        /// @brief  This function is called at beginning of each frame by game engine.
        ///         Objects waiting in the queue to be added will now be available to
        ///         use in this frame. Those objects set to die will be removed.
        void update();
    };
}