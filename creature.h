#ifndef __Creature__
#define __Creature__

#include <string>
#include "entity.h"

class Room;
class Item;

using namespace std;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Room* room);
	~Creature();

	virtual bool Go(const string& direction);
	virtual void Look(const string& arguments) const;
	virtual bool Take(const string& arguments);
	virtual bool Drop(const string& arguments);
	virtual void Inventory() const;
	virtual bool Equip(const string& arguments);
	virtual bool UnEquip(const string& arguments);
	virtual bool AutoEquip();
	virtual void Tick();

	virtual bool Attack(const string& arguments);
	virtual int MakeAttack();
	virtual int ReceiveAttack(int damage);
	virtual void Die();
	virtual bool Loot(const string& arguments);
	virtual void Stats() const;

	Room* GetRoom() const;
	bool PlayerInRoom() const;
	bool IsAlive() const;

public :

	int hit_points;
	int min_damage;
	int max_damage;
	int min_protection;
	int max_protection;
	Creature* combat_target;
	Item* weapon;
	Item* armour;
};

#endif //__Creature__