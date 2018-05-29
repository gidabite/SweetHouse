#include "process.h"

Process::Process()
{

}

void Process::addWorker(Worker *worker)
{
    workers << worker;
}
