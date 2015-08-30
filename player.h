#ifndef __Player__
#define __Player__

#include "creature.h"

using namespace std;

class Player : public Creature
{
public:
	Player(const char* name, const char* description, Room* room);
	~Player();

public :

};

#endif //__Player__