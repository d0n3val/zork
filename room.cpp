#include <iostream>
#include "exit.h"
#include "room.h"

// ----------------------------------------------------
Room::Room(const char* title, const char* description) :
Entity(title, description, NULL)
{

}

// ----------------------------------------------------
Room::~Room()
{
	for(list<Exit*>::iterator it = exits.begin(); it != exits.end(); ++it)
		delete *it;
}

// ----------------------------------------------------
void Room::Look() const
{
	cout << name << "\n";
	cout << description << "\n";

	for(list<Exit*>::const_iterator it = exits.begin(); it != exits.cend(); ++it)
	{
		Exit* ex = *it;	
		cout << "Direction (" << ex->name << ") you see " << ex->parent->name;
	}
}

// ----------------------------------------------------
Exit* Room::GetExit(const string& direction) const
{
	for(list<Exit*>::const_iterator it = exits.begin(); it != exits.cend(); ++it)
	{
		Exit* ex = *it;
		if(ex->name == direction)
			return ex;
	}

	return NULL;
}

// ----------------------------------------------------
void Room::AddExit(const char* name, const char* description, Room* destination)
{
	exits.push_back(new Exit(name, description, destination));
}