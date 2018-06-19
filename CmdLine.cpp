#include "CmdLine.h"
#include <vector>
#include <ncurses.h>
#include <string>
#include <map>

CmdLine::CmdLine()
{
	initscr();
	raw();
}

CmdLine::~CmdLine()
{
	endwin();
}

WINDOW *CmdLine::init_cmd()
{
	int height = 3;
	int width = COLS - 2;
	int pos_y = LINES - height;
	int pos_x = 1;

	WINDOW *cmd_win = newwin(height, width, pos_y, pos_x);
	box(cmd_win, 0, 0);

	mvwaddch(cmd_win, 1, 1, '>');

	wrefresh(cmd_win);

	return cmd_win;
}

// callback_list_type is a map of strings and function pointers
void CmdLine::get_cmd(WINDOW *cmd_line, callback_list_type callback_list)
{
	// this is the container for what the user just typed
	const char cmd_size = 50;
	char cmd[cmd_size];

	// clears the screen from any remaining commands
	redraw_cmd(cmd_line);

	// puts the cursur in the command line, lets the user type a command
	mvwgetnstr(cmd_line, 1, 3, cmd, cmd_size);

	// callback list is a map that contains a string key and a function pointer value.
	//  this grabs an iterator to the the match it found.
	//  if there is not a match, find returns the iterator, which will point to the
	//  the last element + 1, which is how the if statement determines whether it found a
	//  match.
	auto the_function = callback_list.find(cmd);
	if (the_function != callback_list.end())
	{
		(*the_function->second)();
	}
}

void CmdLine::redraw_cmd(WINDOW *cmd_line)
{
	wclear(cmd_line);
	box(cmd_line, 0, 0);
	mvwaddch(cmd_line, 1, 1, '>');

	wrefresh(cmd_line);
}
