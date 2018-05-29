#include "worker.h"

Worker::Worker()
{

}

Worker::Worker(QString fio, QString pSerias, QString pNumber)
{
    this->maskPossibleSpecs = 0;
    this->maskUsedSpecs = 0;
    this->FIO = fio;
    this->passportSeries = pSerias;
    this->passportNumber = pNumber;
    this->isBusy = false;
}

Worker::~Worker(){}

void Worker::addPossibleSpecialization(Specialization *posibleSpec) throw(PossibleSpecializationAlreadyExistExeption)
{
    if (!isExistPossibleSpecialization(posibleSpec)) this->maskPossibleSpecs += posibleSpec->getId();
    else throw PossibleSpecializationAlreadyExistExeption(posibleSpec);
}

void Worker::removePossibleSpecialization(Specialization* posibleSpec) throw(PossibleSpecializationNotExistExeption)
{
    if (isExistPossibleSpecialization(posibleSpec)) this->maskPossibleSpecs -= posibleSpec->getId();
    else throw PossibleSpecializationNotExistExeption(posibleSpec);
}

bool Worker::getIsBusy() const
{
    return isBusy;
}

void Worker::setIsBusy(bool value)
{
    isBusy = value;
}

QString Worker::getPassportNumber() const
{
    return passportNumber;
}

void Worker::setPassportNumber(const QString &value)
{
    passportNumber = value;
}

QString Worker::getPassportSeries() const
{
    return passportSeries;
}

void Worker::setPassportSeries(const QString &value)
{
    passportSeries = value;
}

QString Worker::getFIO() const
{
    return FIO;
}

void Worker::setFIO(const QString &value)
{
    FIO = value;
}

uint Worker::getId() const
{
    return id;
}

void Worker::setId(const uint &value)
{
    id = value;
}

void Worker::addUsedSpecialization(Specialization *spec) throw (PossibleSpecializationNotExistExeption, UsedSpecializationAlreadyExist)
{
    if (isExistPossibleSpecialization(spec)){
        if (!isExistUsedSpecializtion(spec)){
            this->maskUsedSpecs += spec->getId();
        } else throw UsedSpecializationAlreadyExist(spec);
    }
    else throw PossibleSpecializationNotExistExeption(spec);
}

void Worker::removeUsedSpecialization(Specialization *spec) throw(UsedSpecializationNotExist)
{
    if (isExistUsedSpecializtion(spec)){
        this->maskUsedSpecs -=spec->getId();
    } else throw UsedSpecializationNotExist(spec);
}

bool Worker::isExistPossibleSpecialization(Specialization *posibleSpec)
{
    return ((posibleSpec->getId() & maskPossibleSpecs) == posibleSpec->getId());
}

bool Worker::isExistUsedSpecializtion(Specialization *spec)
{
    return ((spec->getId() & maskUsedSpecs) == spec->getId());
}

void Worker::read(const QJsonObject &jsonObj)
{
    this->FIO = jsonObj["FIO"].toString();
    this->passportSeries = jsonObj["pSeries"].toString();
    this->passportNumber = jsonObj["pNumber"].toString();
    this->maskPossibleSpecs = jsonObj["mPS"].toString().toUInt();
    this->maskUsedSpecs = jsonObj["mUS"].toString().toUInt();
    this->isBusy = jsonObj["isBusy"].toBool();
}

void Worker::write(QJsonObject & jsonObj) const
{
    jsonObj["FIO"] = this->FIO;
    jsonObj["pSeries"] = this->passportSeries;
    jsonObj["pNumber"] = this->passportNumber;
    jsonObj["mPS"] = QString::number(this->maskPossibleSpecs);
    jsonObj["mUS"] = QString::number(this->maskUsedSpecs);
    jsonObj["isBusy"] = QJsonValue(this->isBusy);
}
