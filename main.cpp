#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <ncurses.h>
#include "Game.h"

void helloWorld()
{
	mvaddstr(1, 1, "Hello World!");
	refresh();
}

int main()
{

	WINDOW *cmd_win = gm.init_cmd();

	std::map<std::string, void (*)(void)> funcs;

	funcs.emplace(std::make_pair("hello", &helloWorld));

	while (true)
	{
		gm.get_cmd(cmd_win, funcs);
		wrefresh(cmd_win);
	}

	std::cin.get();
	return 0;
}
