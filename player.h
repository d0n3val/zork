#ifndef __Player__
#define __Player__

#include "creature.h"

using namespace std;

class Player : public Creature
{
public:
	Player(const char* name, const char* description, Room* room);
	~Player();

	bool Go(const vector<string>& args);
	void Look(const vector<string>& args) const;
	bool Take(const vector<string>& args);
	bool Drop(const vector<string>& args);
	void Inventory() const;
	bool Equip(const vector<string>& args);
	bool UnEquip(const vector<string>& args);
	bool Examine(const vector<string>& args) const;
	bool Attack(const vector<string>& args);
	bool Loot(const vector<string>& args);
	bool Lock(const vector<string>& args);
	bool UnLock(const vector<string>& args);

public :

};

#endif //__Player__