#ifndef __Entity__
#define __Entity__

#include <string>
#include <list>

using namespace std;

class Entity
{
public:
	Entity(const char* name, const char* description, Entity* parent);
	virtual ~Entity();

	virtual void Look() const;

public :
	std::string name;
	std::string description;

	Entity* parent;
	list<Entity*> container;
};

#endif //__Entity__