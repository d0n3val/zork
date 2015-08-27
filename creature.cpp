#include <iostream>
#include "globals.h"
#include "room.h"
#include "exit.h"
#include "item.h"
#include "creature.h"

// ----------------------------------------------------
Creature::Creature(const char* title, const char* description, Room* room) :
Entity(title, description, (Entity*)room)
{
	type = CREATURE;
}

// ----------------------------------------------------
Creature::~Creature()
{

}

// ----------------------------------------------------
void Creature::Look(const string& arguments) const
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
		cout << name << "\n";
		cout << description << "\n";
	}
	else
	{
		parent->Look();
	}
}

// ----------------------------------------------------
bool Creature::Go(const string& direction)
{
	Exit* exit = GetRoom()->GetExit(direction);

	if(exit == NULL)
	{
		cout << "There is no exit at that direction\n";
		return false;
	}

	cout << "You take direction " << direction << "...\n";
	ChangeParentTo(exit->GetDestinationFrom((Room*) parent));
	parent->Look();

	return true;
}


// ----------------------------------------------------
bool Creature::Take(const string& arguments)
{
	Item* item = (Item*) parent->Find(arguments, ITEM);

	if(item == NULL)
	{
		cout << "There is no item here with that name\n";
		return false;
	}

	cout << "You take " << item->name << "...\n";
	item->ChangeParentTo(this);

	return true;
}

// ----------------------------------------------------
void Creature::Inventory() const
{
	list<Entity*> items;
	FindAll(ITEM, items);

	if(items.size() == 0)
	{
		cout << "You do not own any item\n";
		return;
	}

	for(list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it)
		cout << (*it)->name << "\n";
}

// ----------------------------------------------------
bool Creature::Drop(const string& arguments)
{
	Item* item = (Item*)Find(arguments, ITEM);

	if(item == NULL)
	{
		cout << "There is no item on you with that name\n";
		return false;
	}

	cout << "You drop " << item->name << "...\n";
	item->ChangeParentTo(parent);

	return true;
}