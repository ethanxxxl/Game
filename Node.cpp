#include "Node.h"

Node::Node()
{

}

Node::Node(Node::node_t data_new)
{
	data = data_new;
}

void Node::changeNode(Node::node_t data_new)
{
	data = data_new;
}

void Node::addToNode(item_t item)
{
	data.emplace(item);
}


