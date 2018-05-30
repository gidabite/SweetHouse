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

Worker* WorkerManager::addWorker(QString lName,QString name, QString mName, QString pSerias, QString pNumber, QList<Specialization*> specs)
{
    workers << Worker(lName, name, mName, pSerias, pNumber, specs);
    workers.last().setId(workers.length() - 1);
    return &(workers.last());
}

Worker *WorkerManager::getWorkerById(uint id)
{
    return &(workers[id]);
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

QList<Worker> WorkerManager::getWorkers() const
{
    return workers;
}

void WorkerManager::deleteWorker(uint id)
{
    workers.removeAt(id);
}

void WorkerManager::read(const QJsonObject &jsonObj)
{
    QJsonArray jsonArray = jsonObj["workers"].toArray();
    foreach(QJsonValue jsonWorker, jsonArray)
    {
        Worker worker;
        worker.read(jsonWorker.toObject());
        workers << worker;
        workers.last().setId(workers.length() - 1);
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
