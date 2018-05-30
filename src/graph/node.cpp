#include "node.h"

Node::Node()
{

}

bool Node::operator >(const Node &b)
{
    return (this->getData() > b.getData());
}

