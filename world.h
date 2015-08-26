#ifndef __World__
#define __World__

#include <string>
#include <list>
#include "room.h"

using namespace std;

class Entity;
class Creature;

class World
{
public :

	World();
	~World();

	bool ReceiveInput(const std::string& input);

private:

	list<Room*> rooms;
	Creature* player;
};

#endif //__World__