#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "globals.h"
#include "world.h"

using namespace std;

// -------------------------------------------------
int main()
{
	char key;
	string player_input;
	vector<string> args(10);
	args.clear();

	cout << "Welcome to MyZork!\n";
	cout << "----------------\n";

	World my_world;
	args.push_back("look");
	my_world.Tick(args);
	args.clear();
	cout << "> ";

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
				Tokenize(player_input, args);
		}

		if(args.size() > 0 && Same(args[0], "quit"))
			break;

		if(my_world.Tick(args) == false)
			cout << "\nSorry, I do not understand your command.\n";

		if(args.size() > 0)
		{
			args.clear();
			player_input = "";
			cout << "> ";
		}
	}

	cout << "\nThanks for playing, Bye!\n";
	return 0;
}