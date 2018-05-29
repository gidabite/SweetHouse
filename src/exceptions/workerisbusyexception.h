#ifndef WORKERISBUSYEXCEPTION_H
#define WORKERISBUSYEXCEPTION_H

#include <QException>

class WorkerIsBusyException : public QException
{
public:
    WorkerIsBusyException();
    QString getMessage();
private:
    QString message;
};

#endif // WORKERISBUSYEXCEPTION_H
