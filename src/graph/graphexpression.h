 #ifndef GRAPHEXPRESSION_H
#define GRAPHEXPRESSION_H

#include "graph.h"
template< class T >
class GraphExpression
{
public:
    static QList<uint> algorithm(Graph<T> graph){
        QList<uint> t;
        t.push_back(0);
        QList<uint> temp = retAlg(graph, t, 0);
        return temp;
    }
private:
    static QList<uint> retAlg(Graph<T> graph, QList<uint> path, uint node){
        if (graph.getEdges(node).empty()){
            path[0] = path[0] + graph.getNode(node)->getData();
            path << node;
            return path;
        } else {
            QList<uint> nodes = graph.getEdges(node);
            path[0] = path[0] + graph.getNode(node)->getData();
            path << node;
            QList<uint> pathRet = path;
            for(QList<uint>::const_iterator iter = nodes.constBegin(); iter != nodes.constEnd(); iter++){
                 QList<uint> tempPath = retAlg(graph, path, *iter);
                if (tempPath[0] >= pathRet[0]){
                    pathRet = tempPath;
                }
            }
            return pathRet;
        }
    }
};

#endif // GRAPHEXPRESSION_H
