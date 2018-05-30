#ifndef PROJECT_H
#define PROJECT_H

#include "../graph/psgraph.h"
#include "../worker/worker.h"
#include "../worker/slot.h"
#include <QString>
#include <QList>

class Project: public Serializable
{
public:
    Project();
    void setWorker(Specialization *spec, Worker *worker) throw (WorkerIsBusyException, PossibleSpecializationNotExistExeption, UsedSpecializationAlreadyExist);
    QList<Worker *> getWorkersBySpecialization(Specialization *spec);
    Slot * getSlotById(uint id);
protected:
    void addSlot(Specialization *spec);
    uint addProcess(QString name, uint stage, uint h);
    void addLink(uint fromNode, uint toNode);
private:
    PSGraph graph;
    QString name;
    QList<Slot> sls; //slots

    // Serializable interface
public:
    void read(const QJsonObject &jsonObj);
    void write(QJsonObject &obj) const;
};

#endif // PROJECT_H
