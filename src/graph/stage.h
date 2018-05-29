#ifndef STAGE_H
#define STAGE_H

#include "process.h"
#include <QString>
#include <QList>

class Stage
{
public:
    Stage();
    Stage(QString name, uint id):name(name), id(id){}
    void addProcess(Process& process);  //??
    const QList<Process const*> getProcesses();  //??
private:
    QString name;
    QList<Process const*> processes; //??
    uint id;
};

#endif // STAGE_H
