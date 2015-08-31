#include <iostream>
#include "globals.h"
#include "room.h"
#include "exit.h"
#include "item.h"
#include "player.h"

// ----------------------------------------------------
Player::Player(const char* title, const char* description, Room* room) :
Creature(title, description, room)
{
	type = PLAYER;
}

// ----------------------------------------------------
Player::~Player()
{
}

// ----------------------------------------------------
void Player::Look(const string& arguments) const
{
	for(list<Entity*>::const_iterator it = parent->container.begin(); it != parent->container.cend(); ++it)
	{
		if(Same((*it)->name, arguments) || ((*it)->type == EXIT && Same(arguments, ((Exit*)(*it))->GetNameFrom((Room*)parent))))
		{
			(*it)->Look();
			return;
		}
	}

	if(Same(arguments, "me"))
	{
		cout << "\n" << name << "\n";
		cout << description << "\n";
	}
	else
	{
		parent->Look();
	}
}

// ----------------------------------------------------
bool Player::Go(const string& direction)
{
	Exit* exit = GetRoom()->GetExit(direction);

	if(exit == NULL)
	{
		cout << "There is no exit at that direction.\n";
		return false;
	}

	cout << "\nYou take direction " << direction << "...\n";
	ChangeParentTo(exit->GetDestinationFrom((Room*)parent));
	parent->Look();

	return true;
}


// ----------------------------------------------------
bool Player::Take(const string& arguments)
{
	Item* item = (Item*)parent->Find(arguments, ITEM);

	if(item == NULL)
	{
		cout << "\nThere is no item here with that name.\n";
		return false;
	}

	cout << "\nYou take " << item->name << "...\n";
	item->ChangeParentTo(this);

	return true;
}

// ----------------------------------------------------
void Player::Inventory() const
{
	list<Entity*> items;
	FindAll(ITEM, items);

	if(items.size() == 0)
	{
		cout << "\nYou do not own any item.\n";
		return;
	}

	for(list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it)
	{
		if(*it == weapon)
			cout << "\n" << (*it)->name << " (as weapon)";
		else if(*it == armour)
			cout << "\n" << (*it)->name << " (as armour)";
		else
			cout << "\n" << (*it)->name;
	}

	cout << "\n";
}

// ----------------------------------------------------
bool Player::Drop(const string& arguments)
{
	Item* item = (Item*)Find(arguments, ITEM);

	if(item == NULL)
	{
		cout << "\nThere is no item on you with that name.\n";
		return false;
	}

	cout << "\nYou drop " << item->name << "...\n";
	item->ChangeParentTo(parent);

	return true;
}

// ----------------------------------------------------
bool Player::Equip(const string& arguments)
{
	Item* item = (Item*)Find(arguments, ITEM);

	if(item == NULL)
	{
		cout << "\n" << item->name << " is not in your inventory.\n";
		return false;
	}

	switch(item->item_type)
	{
		case WEAPON:
		weapon = item;
		break;

		case ARMOUR:
		armour = item;
		break;

		default:
		cout << "\n" << item->name << " cannot be equipped.\n";
		return false;
	}
		
	cout << "\nYou equip " << item->name << "...\n";

	return true;
}

// ----------------------------------------------------
bool Player::UnEquip(const string& arguments)
{
	if(!IsAlive())
		return false;

	Item* item = (Item*)Find(arguments, ITEM);

	if(item == NULL)
	{
		cout << "\n" << item->name << " is not in your inventory.\n";
		return false;
	}

	if(item == weapon)
		weapon = NULL;
	else if(item == armour)
		armour = NULL;
	else
	{
		cout << "\n" << item->name << " is not equipped.\n";
		return false;
	}

	cout << "\nYou un-equip " << item->name << "...\n";

	return true;
}

// ----------------------------------------------------
bool Player::Examine(const string& arguments) const
{
	Creature *target = (Creature*) parent->Find(arguments, CREATURE);

	if(target == NULL)
	{
		cout << "\n" << arguments << " is not here.\n";
		return false;
	}

	target->Inventory();

	return true;
}

// ----------------------------------------------------
bool Player::Attack(const string& arguments)
{
	Creature *target = (Creature*)parent->Find(arguments, CREATURE);

	if(target == NULL)
	{
		cout << "\n" << arguments << " is not here.";
		return false;
	}

	combat_target = target;
	cout << "\nYou jump to attack " << target->name << "!\n";
	return true;
}

// ----------------------------------------------------
bool Player::Loot(const string& arguments)
{
	Creature *target = (Creature*)parent->Find(arguments, CREATURE);

	if(target == NULL)
	{
		cout << "\n" << arguments << " is not here.\n";
		return false;
	}

	if(target->IsAlive() == true)
	{
		cout << "\n" << arguments << " cannot be looted until it is killed.\n";
		return false;
	}

	list<Entity*> items;
	target->FindAll(ITEM, items);

	if(items.size() > 0)
	{
		cout << "\nYou loot " << target->name << "'s corpse:\n";

		for(list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it)
		{
			Item* i = (Item*)(*it);
			cout << "You find: " << i->name << "\n";
			i->ChangeParentTo(this);
		}
	}
	else
		cout << "\nYou loot " << target->name << "'s corpse, but find nothing there.\n";

	return true;
}