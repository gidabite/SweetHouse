#ifndef NODE_H
#define NODE_H
#include <QtCore>

class Node
{
public:
    Node();
    bool operator > (const Node &b);
    virtual uint getData() const = 0;
};
#endif // NODE_H
