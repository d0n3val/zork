#ifndef __Room__
#define __Room__

#include <string>
#include <list>
#include "entity.h"

class Exit;

using namespace std;

class Room : public Entity
{
public:
	Room(const char* name, const char* description);
	~Room();

	void Look() const;
	Exit* GetExit(const string& direction) const;
	void AddExit(const char* name, const char* description, Room* destination);

public :
	list<Exit*> exits;
};

#endif //__Room__