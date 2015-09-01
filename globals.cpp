#include "globals.h"

//using namespace std;

// -------------------------------------------------
bool Same(const string& a, const string& b)
{
	return _stricmp(a.c_str(), b.c_str()) == 0;
}

bool Same(const char* a, const string& b)
{
	return _stricmp(a, b.c_str()) == 0;
}

bool Same(const string& a, const char* b)
{
	return _stricmp(a.c_str(), b) == 0;
}

int Roll(int min, int max)
{
	return (max > 0) ? min + (rand() % (max - min)) : 0;
}

void Tokenize(const string& line, vector<string>& arguments)
{
	const char* str = line.c_str();

	do
	{
		const char *begin = str;

		while(*str != ' ' && *str)
			str++;

		arguments.push_back(string(begin, str));
	} while(0 != *str++);
}
