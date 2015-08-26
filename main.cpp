#include <iostream>
#include <string>
#include "world.h"

using namespace std;

int main()
{
	cout << "Welcome to Zork!\n";
	cout << "----------------\n\n";
	string player_input;

	World my_world;
	my_world.ReceiveInput("look");

	while(1)
	{
		cout << "\n> ";
		getline(std::cin, player_input);

		if(player_input == "quit")
			break;

		if(my_world.ReceiveInput(player_input) == false)
			cout << "Sorry, I do not understand your command.";
	}

	cout << "\nThanks for playing, Bye!\n";
	return 0;
}