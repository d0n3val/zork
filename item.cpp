#include <iostream>
#include "room.h"
#include "exit.h"
#include "item.h"

// ----------------------------------------------------
Item::Item(const char* title, const char* description, Entity* parent, ItemType item_type) :
Entity(title, description, parent), item_type(item_type)
{
	type = ITEM;
	min_value = max_value = 0;
}

// ----------------------------------------------------
Item::~Item()
{}
