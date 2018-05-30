#ifndef PSGRAPH_H
#define PSGRAPH_H

#include <QString>
#include "graph.h"
#include "process.h"

class PSGraph: public Graph<Process>
{
public:
    PSGraph();
    uint addProcess(QString& name,  uint stage, uint h);
};

#endif // PSGRAPH_H
