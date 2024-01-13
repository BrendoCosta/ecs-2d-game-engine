#include "Object.h"

Project::Entity::Object::Object()
{
}

Project::Entity::Object::Object(Project::Entity::Tag tag, std::size_t id): m_tag(tag), m_id(id)
{
}

void Project::Entity::Object::destroy()
{
    this->m_alive = false;
}

std::size_t Project::Entity::Object::get_id() const
{
    return this->m_id;
}

Project::Entity::Tag Project::Entity::Object::get_tag() const
{
    return this->m_tag;
}

bool Project::Entity::Object::is_alive() const
{
    return this->m_alive;
}