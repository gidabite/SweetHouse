#ifndef GRAPH_H
#define GRAPH_H

#include "exceptions/nullnodeexception.h"
#include <QList>

template <class T>
class Graph
{
public:
    Graph(){}
    bool addEdge(uint fromNode, uint toNode){
        edges[fromNode] << toNode;
        return true;
    }

protected:
    QList<T const*> nodes;
    QList<QList<uint>> edges;

    uint addNode(const T& node){
        nodes << &node;
        edges << QList<uint>();
        return nodes.length() - 1;
    }
};

#endif // GRAPH_H
