#include <iostream>
#include "room.h"
#include "exit.h"
#include "item.h"

// ----------------------------------------------------
Item::Item(const char* title, const char* description, Room* room) :
Entity(title, description, (Entity*)room)
{
	type = ITEM;
}

// ----------------------------------------------------
Item::~Item()
{

}
