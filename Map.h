#ifndef MAP_H
#define MAP_H

#include "Game.h"
#include "Node.h"
#include <string>
#include <map>

class Map: Game
{
private:
	// these are the things that can be collected, and will spawn on the map
	// in each spot. the number is the rarity of each item.
	typedef std::map<std::string, float> all_items_t;

	static all_items_t items;

public:
	static std::vector<std::vector<Node>> world_map;
	
	// generates the world and all the items on each spot
	void generate(int size, all_items_t alt_list = items);

};

#endif
