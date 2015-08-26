#ifndef __Exit__
#define __Exit__

#include <string>
#include "entity.h"

class Room;

using namespace std;

class Exit : public Entity
{
public:
	Exit(const char* name, const char* description, Room* destination);
	~Exit();

	Room* GetDestination() const
	{
		return (Room*)parent;
	}

public :
	bool closed;
	bool locked;
	Entity* key;
};

#endif //__Exit__