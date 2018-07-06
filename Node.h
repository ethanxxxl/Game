#ifndef NODE_H
#define NODE_H

#include <string>
#include <map>
#include <vector>

class Node
{
public:
	typedef std::map<std::string, int> node_t;
	typedef std::pair<std::string, int> item_t;

	Node();
	Node(node_t data_new);

	// views all the items in a spot
	void viewNode(void);

	// completely changes the entire structure of the node
	void changeNode(node_t data_new);

	// appends one item to the end of the node
	void addToNode(item_t item);


private:
	node_t data;
};

#endif

