#ifndef PROCESS_H
#define PROCESS_H

#include "node.h"
#include "../worker/worker.h"
#include <QString>

class Process: public Node
{
public:
    Process();
    Process(QString name, uint idStage): name(name), idStage(idStage){}
    void addWorker(Worker *worker);
private:
    QString name;
    QList<Worker*> workers;
    uint idStage;
};

#endif // PROCESS_H
