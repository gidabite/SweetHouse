#include "workerisbusyexception.h"

WorkerIsBusyException::WorkerIsBusyException()
{
    message = "This worker is already busy";
}

QString WorkerIsBusyException::getMessage()
{
    return message;
}
