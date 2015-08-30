#ifndef __Player__
#define __Player__

#include "creature.h"

using namespace std;

class Player : public Creature
{
public:
	Player(const char* name, const char* description, Room* room);
	~Player();

	bool Go(const string& direction);
	void Look(const string& arguments) const;
	bool Take(const string& arguments);
	bool Drop(const string& arguments);
	void Inventory() const;

public :

};

#endif //__Player__