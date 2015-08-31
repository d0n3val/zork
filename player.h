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
	bool Equip(const string& arguments);
	bool UnEquip(const string& arguments);
	bool Examine(const string& arguments) const;
	bool Attack(const string& arguments);
	bool Loot(const string& arguments);

public :

};

#endif //__Player__