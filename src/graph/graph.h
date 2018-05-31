#ifndef GRAPH_H
#define GRAPH_H

#include "exceptions/nullnodeexception.h"
#include "../serialization/serializable.h"
#include <QList>
#include <QJsonArray>

template <class T>
class Graph : public Serializable
{
public:
    Graph(){}
    bool addEdge(uint fromNode, uint toNode){
        edges[fromNode] << toNode;
        return true;
    }
    uint addNode(const T& node){
        nodes << node;
        edges << QList<uint>();
        return nodes.length() - 1;
    }
    T* getNode(uint id){
        return &nodes[id];
    }
    uint countNodes(){
        return nodes.length();
    }
protected:
    QList<T> nodes;
    QList<QList<uint>> edges;


    // Serializable interface
public:
    void read(const QJsonObject &jsonObj)
    {
        QJsonArray jsonArrayNodes = jsonObj["nodes"].toArray();
        foreach(QJsonValue jsonNode, jsonArrayNodes)
        {
            T node;
            node.read(jsonNode.toObject());
            nodes << node;
        }
        QJsonArray jsonArrayEdges = jsonObj["edges"].toArray();
        foreach(QJsonValue jsonNodeEdges, jsonArrayEdges)
        {
            QList<uint> edgesNode;
            foreach(QJsonValue jsonEdge, jsonNodeEdges.toArray())
            {
                uint value = (jsonEdge.toObject())["node"].toString().toUInt();
                edgesNode << value;
            }
            edges << edgesNode;
        }
    }
    void write(QJsonObject &obj) const{
        QJsonArray jsonArrayNodes;
        for (typename QList<T>::const_iterator iter = nodes.constBegin(); iter != nodes.constEnd(); iter++){
            QJsonObject jsonNode;
            iter->write(jsonNode);
            jsonArrayNodes.append(jsonNode);
        }
        obj["nodes"] = jsonArrayNodes;
        QJsonArray jsonArrayEdges;
        for (QList<QList<uint>>::const_iterator iter = edges.constBegin(); iter != edges.constEnd(); iter++){
            QJsonArray jsonNodeEdges;
            for (QList<uint>::const_iterator iter2 = iter->constBegin(); iter2 != iter->constEnd(); iter2++){
                QJsonObject jsonEdge;
                jsonEdge["node"] = QString::number(*iter2);
                jsonNodeEdges.append(jsonEdge);
            }
            jsonArrayEdges.append(jsonNodeEdges);
        }
        obj["edges"] = jsonArrayEdges;
    }
};

#endif // GRAPH_H
