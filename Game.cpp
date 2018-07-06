#include "Game.h"
#include <ncurses.h>
#include <panel.h>

Game::Game()
{
	if ( stdscr == NULL )
	{
		// starts ncurses, with color!
		initscr();
		start_color();
	}
}

Game::~Game()
{
	// stops ncurses on exit.
	endwin();
}

void Game::show()
{
	// this will show a panel, in theory.
	top_panel(panel);
	refresh();
}

void Game::hide()
{
	// this will hide a panel, in theory.
	hide_panel(panel);
	refresh();
}

void Game::inputHandler()
{
}
