#include "stage.h"

Stage::Stage()
{

}

void Stage::addProcess(Process &process)
{
    processes << &process;
}

const QList<const Process *> Stage::getProcesses()
{
    return processes;
}
