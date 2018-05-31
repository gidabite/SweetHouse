#include "slot.h"

Slot::Slot():isBusy(false), worker(nullptr), spec(EmptySpecialization::instance()){}

Slot::Slot(Specialization *spec):isBusy(false), worker(nullptr), spec(spec){}

void Slot::setWorker(Worker *newWorker) throw (WorkerIsBusyException, PossibleSpecializationNotExistExeption, UsedSpecializationAlreadyExist)
{
    if (!newWorker->getIsBusy()){
        if (newWorker->isExistPossibleSpecialization(spec)){
            if (!newWorker->isExistUsedSpecializtion(spec)){
                if (worker != nullptr) {
                    worker->setIsBusy(false);
                    worker->removeUsedSpecialization(spec);
                }
                worker = newWorker;
                worker->setIsBusy(true);
                worker->addUsedSpecialization(spec);
                this->isBusy = true;
            } else throw UsedSpecializationAlreadyExist(spec);
        } else throw PossibleSpecializationNotExistExeption(spec);
    } else throw WorkerIsBusyException();
}

void Slot::removeWorker(){ worker = nullptr; }

uint Slot::getSpeceializationId() const{
    return spec->getId();
}

bool Slot::getIsBusy() const
{
    return isBusy;
}

void Slot::setIsBusy(bool value)
{
    isBusy = value;
}

Worker *Slot::getWorker()
{
    return worker;
}

uint Slot::getId() const
{
    return id;
}

void Slot::setId(const uint &value)
{
    id = value;
}

void Slot::read(const QJsonObject &jsonObj)
{
    this->isBusy = jsonObj["isBusy"].toBool();
    uint spec = jsonObj["spec"].toString().toUInt();
    switch (spec) {
    case 0:
        this->spec = EmptySpecialization::instance();
        break;
    case 1:
        this->spec = EmptySpecialization::instance();
        break;
    case 2:
        this->spec = EmptySpecialization::instance();
        break;
    case 4:
        this->spec = EmptySpecialization::instance();
        break;
    case 8:
        this->spec = EmptySpecialization::instance();
        break;
    case 16:
        this->spec = EmptySpecialization::instance();
        break;
    case 32:
        this->spec = EmptySpecialization::instance();
        break;
    case 64:
        this->spec = EmptySpecialization::instance();
        break;
    }
    if (jsonObj["workerId"] != "")
        this->worker = WorkerManager::instance()->getWorkerById(jsonObj["workerId"].toString().toUInt());
}

void Slot::write(QJsonObject &obj) const
{
    obj["isBusy"] = QJsonValue(this->isBusy);
    obj["spec"] = QString::number(this->spec->getId());
    if (this->worker)
        obj["workerId"] = QString::number(this->worker->getId());
}


