#include <iostream>
#include <string>
#include "globals.h"
#include "world.h"

using namespace std;

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
// -------------------------------------------------

int main()
{
	cout << "Welcome to Zork!\n";
	cout << "----------------\n\n";
	string player_input;

	World my_world;
	my_world.ReceiveInput("look", "");

	while(1)
	{
		cout << "\n> ";
		getline(cin, player_input);
		size_t pos = player_input.find(' ');
		
		string command = player_input;
		string arguments = "";

		if(pos != string::npos)
		{
			command = player_input.substr(0, pos);
			arguments = player_input.substr(pos+1);
		} 

		if(Same(command, "quit"))
			break;

		if(my_world.ReceiveInput(command, arguments) == false)
			cout << "Sorry, I do not understand your command.";
	}

	cout << "\nThanks for playing, Bye!\n";
	return 0;
}