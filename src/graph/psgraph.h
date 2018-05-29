#ifndef PSGRAPH_H
#define PSGRAPH_H

#include <QString>
#include "graph.h"
#include "process.h"
#include "stage.h"

class PSGraph: public Graph<Process>
{
public:
    PSGraph();
    uint addProcess(QString& name,  uint stage);
    uint addStage(QString& name);
private:
    QList<Stage> stages;
};

#endif // PSGRAPH_H
