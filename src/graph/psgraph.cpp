#include "psgraph.h"

PSGraph::PSGraph()
{

}


uint PSGraph::addProcess(QString& name, uint stage, uint h)
{
    Process newProcess(name, stage, h);
    return this->addNode(newProcess);
}
