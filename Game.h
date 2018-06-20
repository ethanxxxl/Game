#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include <string>
#include <map>

class Game
{
private:
	typedef void (*callback_func)(WINDOW *);
	typedef std::map<std::string, callback_func> callback_list_type;

	void test(WINDOW *);
	void exit(WINDOW *);
	void echo(WINDOW *);
	
	//TODO: make a callback list and add all the commandline functions to it.

public:
	//this class is going the be the drawing class, so there will be some puplic functions here
	// for drawing different sized windows for different attributes of the game.
};

#endif
