#include <iostream>
#include "room.h"
#include "exit.h"
#include "creature.h"

// ----------------------------------------------------
Creature::Creature(const char* title, const char* description, Room* room) :
Entity(title, description, (Entity*)room)
{

}

// ----------------------------------------------------
Creature::~Creature()
{

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

	cout << "You take direction " << exit->name << "...\n";
	parent = exit->parent;
	parent->Look();

	return true;
}