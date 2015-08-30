#ifndef __World__
#define __World__

#include <string>
#include <list>
#include <time.h>

#define TICK_FREQUENCY 0.5f

using namespace std;

class Entity;
class Player;

class World
{
public :

	World();
	~World();

	bool Tick(const string& command, const string& arguments);
	bool ParseCommand(const string& command, const string& arguments);
	void GameLoop();

private:

	clock_t tick_timer;
	list<Entity*> entities;
	Player* player;
};

#endif //__World__