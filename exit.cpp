#include <iostream>
#include "room.h"
#include "Exit.h"

// ----------------------------------------------------
Exit::Exit(const char* title, const char* description, Room* destination) :
Entity(title, description, (Entity*)destination),
closed(false), locked(false), key(NULL)
{

}

// ----------------------------------------------------
Exit::~Exit()
{

}
