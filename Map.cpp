#include "Map.h"
#include "Node.h"
#include <random>

void Map::generate(int size)
{
	world_map.resize(size);

	for ( int x = 0; x <= size; x++ )
	{
		// this loops through the first layer and expands each vector in the
		//  second dimension
		world_map[x].resize(size);

		
		for ( int y = 0; y <= size; y++ )
		{
			for
			
			world_map[x][y];
		}
	}
}


Map::all_items_t Map::items =
{
	{"Wood",    0.0f},
	{"Rock",    0.0f},
	{"Fiber",   0.0f},
	{"Water",   0.0f},
	{"Metal",   0.0f}
};
