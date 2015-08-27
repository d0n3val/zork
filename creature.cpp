#include <iostream>
#include "globals.h"
#include "room.h"
#include "exit.h"
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
	parent = exit->GetDestinationFrom((Room*) parent);
	parent->Look();

	return true;
}