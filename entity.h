#ifndef __Entity__
#define __Entity__

#include <string>
#include <list>

using namespace std;

enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	CREATURE
};

class Entity
{
public:
	Entity(const char* name, const char* description, Entity* parent);
	virtual ~Entity();

	virtual void Look() const;
	void ChangeParentTo(Entity* new_parent);
	Entity* Find(const string& name, EntityType type) const;
	void FindAll(EntityType type, list<Entity*>& list_to_fill) const;

public :
	EntityType type;
	std::string name;
	std::string description;

	Entity* parent;
	list<Entity*> container;
};

#endif //__Entity__