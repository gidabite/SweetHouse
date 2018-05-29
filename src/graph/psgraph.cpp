#include "psgraph.h"

PSGraph::PSGraph()
{

}

uint PSGraph::addStage(QString& name)
{
    stages << Stage(name, stages.length());
    return stages.length() - 1;
}

uint PSGraph::addProcess(QString& name, uint stage)
{
    Process newProcess(name, stage);
    stages[stage].addProcess(newProcess);
    return this->addNode(newProcess);
}
