#ifndef __Item__
#define __Item__

#include <string>
#include "entity.h"

class Room;

using namespace std;

class Item : public Entity
{
public:
	Item(const char* name, const char* description, Room* room);
	~Item();


public :

};

#endif //__Item__