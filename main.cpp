#include <iostream>
#include <string>
#include <conio.h>
#include "globals.h"
#include "world.h"

using namespace std;

// -------------------------------------------------
int main()
{
	cout << "Welcome to MyZork!\n";
	cout << "----------------\n";
	string player_input;

	World my_world;
	my_world.Tick("look", "");
	cout << "> ";

	string command;
	string arguments;
	char key;

	while(1)
	{
		if(_kbhit() != 0)
		{
			key = _getch();
			if(key == '\b') // backspace
			{
				if(player_input.length() > 0)
				{
					player_input[player_input.length() - 1] = '\0';
					cout << '\b';
					cout << " ";
					cout << '\b';
				}
			}
			else if(key != '\r') // return
			{
				player_input += key;
				cout << key;
			}

			else
			{	
				size_t pos = player_input.find(' ');

				command = player_input;

				if(pos != string::npos)
				{
					command = player_input.substr(0, pos);
					arguments = player_input.substr(pos + 1);
				}
			}
		}

		if(Same(command, "quit"))
			break;

		if(my_world.Tick(command, arguments) == false)
			cout << "\nSorry, I do not understand your command.\n";

		if(command.length() > 0)
		{
			command = "";
			arguments = "";
			player_input = "";
			cout << "> ";
		}
	}

	cout << "\nThanks for playing, Bye!\n";
	return 0;
}