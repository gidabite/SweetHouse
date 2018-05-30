#ifndef WORKERMANAGER_H
#define WORKERMANAGER_H

#include "singleton.h"
#include "worker/worker.h"
#include <QJsonArray>
#include <QFile>
#include "serialization/serializer.h"

class WorkerManager: public Singleton<WorkerManager>, public Serializable
{
    friend class Singleton<WorkerManager>;
    friend class Serializer<WorkerManager>;
public:
    QList<Worker *> getWorkersByPossibleSpecialization(Specialization *spec);
    Worker* addWorker(QString lName,QString name, QString mName, QString pSerias, QString pNumbe, QList<Specialization*> specsr);
    void serializationWorker();
    Worker* getWorkerById(uint id);
    QList<Worker> getWorkers() const;
    void deleteWorker(uint ids);
private:
    WorkerManager();
    QList<Worker> workers;
    // Serializable interface
    void read(const QJsonObject &jsonObj);
    void write(QJsonObject &obj) const;
};

#endif // WORKERMANAGER_H
