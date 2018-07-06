#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <ncurses.h>
#include "Map.h"
#include "CommandLine.h"

// this is very bad, only going to be temporary though.
bool keep_running = true;

namespace cmdFuncs
{
	void helloWorld()
	{
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
		attron(COLOR_PAIR(2));
		mvaddstr(1, 1, "Hello World!");
		refresh();
		attroff(COLOR_PAIR(2));
	}

	void quit()
	{
		keep_running = false;
	}

	void viewmap()
	{
		Map mp;
		mp.generate(20);
		mp.show();
		mp.setActiveNode(1,1);
		mp.inputHandler();
		refresh();
	}
}


int main()
{
	CommandLine cmd;

	cmd.callback_list.emplace("test", &cmdFuncs::helloWorld);
	cmd.callback_list.emplace("quit", &cmdFuncs::quit);
	cmd.callback_list.emplace("viewmap", &cmdFuncs::viewmap);

	while ( keep_running )
	{
		cmd.getCommand();
	}

	return 0;
}
