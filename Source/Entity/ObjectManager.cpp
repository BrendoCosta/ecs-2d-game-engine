#include "ObjectManager.h"
#include <algorithm>
#include <functional>

Project::Entity::ObjectManager::ObjectManager()
{
    
}

std::shared_ptr<Project::Entity::Object> Project::Entity::ObjectManager::add_object(Project::Entity::Tag tag)
{
    auto e = std::shared_ptr<Project::Entity::Object>(new Object(tag, ++this->m_total_objects_so_far));
    this->m_objects_waiting_to_be_added.push(e);
    return e;
}

Project::Entity::ObjectVector& Project::Entity::ObjectManager::get_objects()
{
    return this->m_objects;
}

Project::Entity::ObjectVector& Project::Entity::ObjectManager::get_objects_by_tag(Project::Entity::Tag tag)
{
    return this->m_objectsMap[tag];
}

void Project::Entity::ObjectManager::update()
{
    // Manages the addition of objects waiting to be added
    
    while (!this->m_objects_waiting_to_be_added.empty())
    {
        std::shared_ptr<Project::Entity::Object> e = this->m_objects_waiting_to_be_added.front();
        this->m_objects.push_back(e);
        this->m_objectsMap[e->get_tag()].push_back(e);
        this->m_objects_waiting_to_be_added.pop();
    }

    // Manages the removal of objects that will be killed

    std::function<bool(std::shared_ptr<Project::Entity::Object>)> remove_object_predicate = [](auto e) { return !e->is_alive(); };
    
    Project::Entity::ObjectVector::iterator to_remove_itetator = std::remove_if(this->m_objects.begin(), this->m_objects.end(), remove_object_predicate);
    this->m_objects.erase(to_remove_itetator, this->m_objects.end());
    
    for (auto& pair : this->m_objectsMap)
    {
        Project::Entity::ObjectVector object_vec = pair.second;
        object_vec.erase(std::remove_if(object_vec.begin(), object_vec.end(), remove_object_predicate));
    }
}