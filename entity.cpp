#include <iostream>
#include "globals.h"
#include "Entity.h"

// ----------------------------------------------------
Entity::Entity(const char* name, const char* description, Entity* parent = NULL) :
name(name), description(description), parent(parent)
{
	type = ENTITY;

	if(parent != NULL)
		parent->container.push_back(this);
}

// ----------------------------------------------------
Entity::~Entity()
{}

// ----------------------------------------------------
void Entity::Look() const
{
	cout << name << "\n";
	cout << description << "\n";
}

// ----------------------------------------------------
void Entity::Tick()
{}

// ----------------------------------------------------
void Entity::ChangeParentTo(Entity* new_parent)
{
	if(parent != NULL)
		parent->container.remove(this);

	parent = new_parent;

	if(parent != NULL)
		parent->container.push_back(this);
}

// ----------------------------------------------------
bool Entity::Find(Entity* entity) const
{
	for(list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
	{
		if((*it) == entity)
			return true;
	}

	return false;
}

// ----------------------------------------------------
Entity* Entity::Find(EntityType type) const
{
	for(list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
	{
		if((*it)->type == type)
			return *it;
	}

	return NULL;
}

// ----------------------------------------------------
Entity* Entity::Find(const string& name, EntityType type) const
{
	for(list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
	{
		if((*it)->type == type)
		{
			if(Same((*it)->name, name))
				return *it;
		}
	}

	return NULL;
}

// ----------------------------------------------------
void Entity::FindAll(EntityType type, list<Entity*>& list_to_fill) const
{
	for(list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
	{
		if((*it)->type == type)
			list_to_fill.push_back(*it);
	}
}