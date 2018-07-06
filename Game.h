#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include <panel.h>
#include <string>
#include <map>
#include "ParseCmd.h"

// TODO: rename this class to something better.
class Game
{
private:

public:
	Game();
	~Game();

	typedef void (*callback_func)(WINDOW *);
	typedef std::map<std::string, callback_func> callback_list_type;

	void show();
	void hide();

	virtual void inputHandler();

protected:
	WINDOW *window;
	PANEL *panel;
	
};

#endif
