#ifndef CMDLINE_H
#define CMDLINE_H
#include <ncurses.h>
#include <string>
#include <map>

class CmdLine
{
private:
	typedef void (*callback_func)(void);
	typedef std::map<std::string, callback_func> callback_list_type;

public:
	CmdLine();
	~CmdLine();

	WINDOW *init_cmd();
	void get_cmd(WINDOW *cmd_line, callback_list_type);
	void redraw_cmd(WINDOW *cmd_line);
};

#endif
