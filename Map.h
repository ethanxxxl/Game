#ifndef MAP_H
#define MAP_H

#include "Game.h"
#include "Node.h"
#include <string>
#include <map>

class Map: public Game
{
private:
	// these are the things that can be collected, and will spawn on the map
	//  in each spot. the number is the rarity of each item.
	typedef std::map<std::string, float> all_items_t;

	// these are just all the items that will spawn on each node in the map
	static all_items_t items;
	static std::pair<int, int> active_node;

	// color definitions
	const int normal_background = 1;
	const int highlight_background = 2;

	const char map_char = 'O';

	WINDOW *info_win = newwin()

public:
	// this is the entire world map.
	std::vector<std::vector<Node>> world_map;

	Map();
	
	// generates the world and all the items on each spot
	void generate(int size, all_items_t item_list = items);
	void setActiveNode(int x, int y);
	void inputHandler();


};

#endif
