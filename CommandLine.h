#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <ncurses.h>
#include <panel.h>
#include <string>

#include "Game.h"


class CommandLine: Game
{
public:
	CommandLine();

	std::map<std::string, void (*)(void)> callback_list;

	void getCommand();
	void clearPrompt();
};

#endif
