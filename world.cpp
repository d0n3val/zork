#include <iostream>
#include "globals.h"
#include "entity.h"
#include "creature.h"
#include "item.h"
#include "exit.h"
#include "room.h"
#include "world.h"

// ----------------------------------------------------
World::World()
{
	// Rooms ----
	Room* forest = new Room("Forest", "You are surrounded by tall trees. It feels like a huge forest someone could get lost easily.");
	Room* house = new Room("House", "You are inside a beautiful but small white house.");

	Exit* ex1 = new Exit("west", "east", "Little path", house, forest);

	entities.push_back(forest);
	entities.push_back(house);
	entities.push_back(ex1);

	// Items -----
	Item* mailbox = new Item("Mailbox", "Looks like it might contain something.", house);

	entities.push_back(mailbox);

	// Player ----
	player = new Creature("Player", "You are an awesome adventurer!", forest);

	entities.push_back(player);
}

// ----------------------------------------------------
World::~World()
{
	for(list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		delete *it;
}

// ----------------------------------------------------
bool World::ReceiveInput(const string& command, const string& arguments)
{
	bool ret = true;
	
	if(Same(command,"look"))
	{
		player->Look(arguments);
	}
	else if(Same(command,"go"))
	{
		player->Go(arguments);
	}
	else if(Same(command, "north") || Same(command, "n"))
	{
		player->Go("north");
	}
	else if(Same(command, "south") || Same(command, "s"))
	{
		player->Go("south");
	}
	else if(Same(command, "east") || Same(command, "e"))
	{
		player->Go("east");
	}
	else if(Same(command, "west") || Same(command, "w"))
	{
		player->Go("west");
	}
	else if(Same(command, "take") || Same(command, "pick"))
	{
		player->Take(arguments);
	}
	else if(Same(command, "drop") || Same(command, "remove"))
	{
		player->Drop(arguments);
	}
	else if(Same(command, "inventory") || Same(command, "i"))
	{
		player->Inventory();
	}
	else
		ret = false;

	return ret;
}