#ifndef CMDLINE_H
#define CMDLINE_H
#include <ncurses.h>
#include <string>
#include <map>

//TODO: move all of the drawing stuff out of this class and merge it with the tokenizer class.
//
// maybe call it the command class or something? idk, jus separate and merge the two so that the game will be more modular
class CmdLine
{
private:
	typedef void (*callback_func)(WINDOW *);
	typedef std::map<std::string, callback_func> callback_list_type;

public:
	CmdLine();
	~CmdLine();

	WINDOW *init_cmd();
	void get_cmd(WINDOW *cmd_line, callback_list_type);
	void redraw_cmd(WINDOW *cmd_line);
};

#endif
