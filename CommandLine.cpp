#include "CommandLine.h"
#include <ncurses.h>
#include <panel.h>

#include "ParseCmd.h"

CommandLine::CommandLine()
{
	window = newwin(3, COLS-2, LINES - 3, 1);
	panel = new_panel(window);

	clearPrompt();
}

void CommandLine::getCommand()
{
	// I'm using a vector<char> becuase these curses functions are written in
	//  C, and want char*, but
	//  this is c++, I don't want to use those.
	std::vector<char> v_str(50);
	// TODO: make the vector<char> behave less like a C string and more like a
	//  vector. It doesn't get bigger as you type.
	mvwgetstr(window, 1, 3, v_str.data());
	std::string str(v_str.data());

	// breaks up what the user just typed into tokens
	ParseCmd parser;
	std::vector<std::string> parsed_cmd = parser.tokenizeString(str);
	
	// searches the list of function pointers for the command that was entered,
	//  ignoring any paremeters for now.
	auto search = callback_list.find(parsed_cmd[0]);

	// determines if a match was actually found, and calls the function pointed
	//  to by the value if appropriate
	if ( search != callback_list.end() )
	{
		search->second();
		refresh();
		clearPrompt();

	}
	else
	{
		// TODO: make a proper "command not found message"
		mvaddstr(3, 1, "command not found...");
		clearPrompt();
		refresh();
	}
}

void CommandLine::clearPrompt()
{
	// this function just clears the prompt window, then adds the border and
	//  the prompt character.
	wclear(window);
	box(window, 0,0);
	mvwaddch(window, 1, 1, '>');
	wrefresh(window);
}
