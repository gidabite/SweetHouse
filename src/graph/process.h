#ifndef PROCESS_H
#define PROCESS_H

#include "node.h"
#include <QString>
#include "../worker/slot.h"

class Process: public Node, public Serializable
{
public:
    Process();
    Process(QString name, uint idStage, uint h): name(name), idStage(idStage), h(h){}
    void addSlot(Slot slot);
    uint getIdStage() const;
    void setIdStage(const uint &value);
private:
    QString name;
    QList<Slot> sls;
    uint idStage;
    uint h;
    // Serializable interface
public:
    void read(const QJsonObject &jsonObj);
    void write(QJsonObject &obj) const;


    // Node interface
public:
    uint getData() const;
};

#endif // PROCESS_H
