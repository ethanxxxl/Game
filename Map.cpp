#include "Map.h"
#include "Node.h"
#include <random>
#include <ncurses.h>
#include <panel.h>

Map::all_items_t Map::items =
{
	{"Wood",    0.0f},
	{"Rock",    0.0f},
	{"Fiber",   0.0f},
	{"Water",   0.0f},
	{"Metal",   0.0f}
};

std::pair<int, int> Map::active_node = std::make_pair(0,0);

Map::Map()
{
	init_pair(normal_background, COLOR_BLACK, COLOR_WHITE);
	init_pair(highlight_background, COLOR_RED, COLOR_CYAN);

	cbreak();
}

void Map::generate(int size, Map::all_items_t item_list)
{
	world_map.resize(size);

	for ( int x = 0; x < size; x++ )
	{
		// this loops through the first layer and expands each vector in the
		//  second dimension
		world_map[x].resize(size);

		// this will loop through all of the nodes, and populate their fields.
		for ( int y = 0; y < size; y++ )
		{
			for ( Map::all_items_t::iterator it = item_list.begin(); it != item_list.end(); it++)
			{
				// checks the probability of an item being present in the node,
				//   then adhelloWorldds it if applicable
				if ( rand() / 100 < it->second )
				{
					// actually adds the item to the node.
					world_map[x][y].addToNode(std::make_pair(it->first, it->second));
				}
			}
		}
	}

	/*
	 * GUI stuff
	 */

	// size of window
	int win_size = 30;
	
	// setting up and initialization of the window and panel fromm Game class.
	window = newwin(win_size, win_size, 0, 0);
	panel = new_panel(window);

	// this is the "icon" to use when populating the map.
	char icon_char = 'O';

	wattron(window, COLOR_PAIR(1));

	// puts in all the node markers, depending on the amount of nodes.
	//  this is currently very primitive and will need some work.
	if ( win_size < size )
	{
		for ( int y = 0; y < win_size; y++ )
		{
			for ( int x = 0; x < win_size; x++ )
			{
				mvwaddch(window, y, x, icon_char);
			}
		}
	}
	else
	{
		for ( int y = 0; y < size; y++ )
		{
			for ( int x = 0; x < size; x++ )
			{
				mvwaddch(window, y, x, icon_char);
			}
		}
	}
	wattroff(window, COLOR_PAIR(1));

	show();
	wrefresh(window);
}

// the coordinates are node coordinates, not screen coordinates.
void Map::setActiveNode(int x, int y)
{
	// this removes the color from the previously active node, so that only one
	//  node is active at a time.
	wattron(window, COLOR_PAIR(normal_background));
	mvwaddch(window, active_node.second, active_node.first, map_char);
	wattroff(window, COLOR_PAIR(normal_background));

	// changes the active node to the requested node.
	active_node = std::make_pair(x, y);

	// TODO: make this more dynamic so that the screen can pan around and show
	//  larger areas. right now it is just using the screen coordinates, but
	//  this will be fixed

	wattron(window, COLOR_PAIR(highlight_background));
	mvwaddch(window, active_node.second, active_node.first, map_char);
	wattroff(window, COLOR_PAIR(highlight_background));

	wrefresh(window);
	// feed Node information to the info panel
}

void Map::inputHandler()
{
	curs_set(0);
	noecho();

	// this is where the users input is stored.
	char ch = ' ';
	
	// when the user presses q, this loop will end and transfer control back to
	//  the console
	while ( ch != 'q' )
	{
		switch (ch)
		{
			case 'j':
				setActiveNode(active_node.first, active_node.second + 1);
				break;
			case 'k':
				setActiveNode(active_node.first, active_node.second - 1);
				break;
			case 'h':
				setActiveNode(active_node.first - 1, active_node.second);
				break;
			case 'l':
				setActiveNode(active_node.first + 1, active_node.second);
				break;
		}

	// grabs the user input
	ch = getch();
	}

	// lets the user see what they are typing again, so it can go back to
	//  the console
	echo();
	curs_set(1);
}
