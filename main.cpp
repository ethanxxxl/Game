#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <ncurses.h>
#include "Game.h"
#include "CommandLine.h"

// this is very bad, only going to be temporary though.
bool keep_running = true;

void helloWorld()
{
	mvaddstr(1, 1, "Hello World!");
	refresh();
}

void quit()
{
	keep_running = false;
}



int main()
{
	CommandLine cmd;

	cmd.callback_list.emplace("test", &helloWorld);
	cmd.callback_list.emplace("quit", &quit);

	while ( keep_running )
	{
		cmd.getCommand();
	}

	return 0;
}
