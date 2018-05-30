#ifndef SLOT_H
#define SLOT_H

#include "specialization.h"
#include "worker.h"
#include "../exceptions/specializations.h"
#include "../exceptions/workerisbusyexception.h"
#include "../serialization/serializable.h"
#include "../workermanager.h"

class Slot: public Serializable
{
public:
    Slot();
    Slot(Specialization *spec);
    void setWorker(Worker *newWorker) throw (WorkerIsBusyException, PossibleSpecializationNotExistExeption, UsedSpecializationAlreadyExist);
    void removeWorker();
    uint getSpeceializationId() const;
    bool getIsBusy() const;
    void setIsBusy(bool value);
    Worker *getWorker();
    uint getId() const;
    void setId(const uint &value);
private:
    bool isBusy;
    Worker* worker;
    Specialization *spec;
    uint id;

    // Serializable interface
public:
    void read(const QJsonObject &jsonObj);
    void write(QJsonObject &obj) const;
};

#endif // SLOT_H
