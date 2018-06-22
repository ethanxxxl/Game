#include "Game.h"
#include <ncurses.h>
#include <panel.h>

Game::Game()
{
	if ( stdscr == NULL )
	{
		initscr();
	}
}

Game::~Game()
{
	endwin();
}

void Game::show()
{
	top_panel(panel);
}

void Game::hide()
{
	hide_panel(panel);
}
