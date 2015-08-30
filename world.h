#ifndef __World__
#define __World__

#include <string>
#include <list>

using namespace std;

class Entity;
class Player;

class World
{
public :

	World();
	~World();

	bool ReceiveInput(const string& command, const string& arguments);

private:

	list<Entity*> entities;
	Player* player;
};

#endif //__World__