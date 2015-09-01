#ifndef __Globals__
#define __Globals__

#include <string>

using namespace std;

bool Same(const string& a, const string& b);
bool Same(const char* a, const string& b);
bool Same(const string& a, const char* b);
int Roll(int min, int max);

#endif //__Globals__