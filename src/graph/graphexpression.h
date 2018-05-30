 #ifndef GRAPHEXPRESSION_H
#define GRAPHEXPRESSION_H

#include "graph.h"
template< class T >
class GraphExpression
{
public:
    static QList<int> algorithm(Graph<T> graph, uint &mas){
        uint res;
        QList<int> temp = retAlg(graph, QList<uint>(), 0, 0, res);
        mas = res;
        return temp;
    }
private:
    static QList<int> retAlg(Graph<T> graph, QList<uint> path, uint node, uint summ, uint &res){
        if (graph.edges[node].empty()){
            res = summ + graph.getNode(node).getData();
            path << node;
            return path;
        } else {
            QList<uint> nodes = graph.edges[node];
            uint resX = summ + graph.getNode(node).getData();
            path << node;
            QList<uint> pathRet;
            for(QList<uint>::const_iterator iter = nodes.constBegin(); iter != nodes.constEnd(); iter++){
                uint tempValue;
               QList<uint> tempPath = retAlg(graph, path, *iter, resX, tempValue);
                if (tempValue >= res){
                    res = tempValue;
                    pathRet = tempPath;
                }
            }
            return pathRet;
        }
    }
};

#endif // GRAPHEXPRESSION_H
