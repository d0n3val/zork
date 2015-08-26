#include <iostream>
#include "entity.h"
#include "creature.h"
#include "world.h"

// ----------------------------------------------------
World::World()
{
	// Rooms ----
	Room* forest = new Room("Forest", "You are surrounded by tall trees. It feels like a huge forest someone could get lost easily.");
	Room* house = new Room("House", "You are inside a beautiful but small white house.");

	forest->AddExit("west", "Little path", house);
	house->AddExit("east", "Little path", forest);

	rooms.push_back(forest);

	// Player ----
	player = new Creature("Player", "You are an awesome adventurer!", forest);
}

// ----------------------------------------------------
World::~World()
{
	for(list<Room*>::iterator it = rooms.begin(); it != rooms.end(); ++it)
		delete *it;
}

// ----------------------------------------------------
bool World::ReceiveInput(const string& input)
{
	bool ret = true;
	
	if(input == "look")
	{
		player->parent->Look();
	}
	else if(input == "look me")
	{
		player->Look();
	}
	else if(input == "north" || input == "n")
	{
		player->Go("north");
	}
	else if(input == "south" || input == "s")
	{
		player->Go("south");
	}
	else if(input == "east" || input == "e")
	{
		player->Go("east");
	}
	else if(input == "west" || input == "w")
	{
		player->Go("west");
	}
	else
		ret = false;

	return ret;
}