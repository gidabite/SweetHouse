#include "workermanager.h"

QList<Worker*> WorkerManager::getWorkersByPossibleSpecialization(Specialization *spec)
{
    QList<Worker*> temp;
    for (QList<Worker>::iterator iter = workers.begin(); iter != workers.end(); iter++){
        if (iter->isExistPossibleSpecialization(spec)){
            temp << &(*iter);
        }
    }
    return temp;
}

Worker* WorkerManager::addWorker(QString fio, QString pSerias, QString pNumber)
{
    workers << Worker(fio, pSerias, pNumber);
    workers.last().setId(workers.length() - 1);
    return &(workers.last());
}

const Worker *WorkerManager::getWorkerById(uint id)
{
    return &(workers.at(id));
}

WorkerManager::WorkerManager()
{
    QFile wFile("workers.json");
    if (wFile.exists()){
        if (wFile.open(QIODevice::ReadOnly))
        {
            QString ser = QString(wFile.readAll());
            Serializer<WorkerManager>::parse(ser, *this);
            wFile.close();
        }
    }
}

void WorkerManager::read(const QJsonObject &jsonObj)
{
    QJsonArray jsonArray = jsonObj["workers"].toArray();
    foreach(QJsonValue jsonWorker, jsonArray)
    {
        Worker worker;
        worker.read(jsonWorker.toObject());
        workers << worker;
    }
}

 void WorkerManager::write(QJsonObject& obj) const
{
    QJsonArray jsonArray;
    for (QList<Worker>::const_iterator iter = workers.constBegin(); iter != workers.constEnd(); iter++){
        QJsonObject jsonWorker;
        iter->write(jsonWorker);
        jsonArray.append(jsonWorker);
    }
    obj["workers"] = jsonArray;
}
