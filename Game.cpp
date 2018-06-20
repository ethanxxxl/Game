#include "Game.h"
#include <ncurses.h>

void Game::test(WINDOW *window)
{
	mvwaddstr(window, 1, 1, "This command works!!!!");
	refresh();
}

void Game::exit(WINDOW *window)
{
	//TODO: go and change the constructors of the classes so that they check if the initscr() has been called
	//
	// also, you need to rearange these classes, find a way to organize these command line functions with the functions
	// that will be handling windows and such.
	//
	// maybe you should merge the tokenizer class and the CmdLine class so that they share the same functions, and do
	// not draw anything to the screen. this way you can keep all the drawing to one class, and maybe its children
	// classes
}

void Game::echo(WINDOW *window)
{
	//TODO: make this work.
}
