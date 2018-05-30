#include "worker.h"

Worker::Worker()
{

}

Worker::Worker(QString lName, QString name, QString mName, QString pSerias, QString pNumber, QList<Specialization*> specs)
{
    this->maskPossibleSpecs = 0;
    this->maskUsedSpecs = 0;
    this->lastName = lName;
    this->name = name;
    this->middleName = mName;
    this->passportSeries = pSerias;
    this->passportNumber = pNumber;
    this->isBusy = false;
    for (QList<Specialization*>::const_iterator iter = specs.constBegin(); iter != specs.constEnd(); iter++){
        addPossibleSpecialization(*iter);
    }
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

QString Worker::getMiddleName() const
{
    return middleName;
}

void Worker::setMiddleName(const QString &value)
{
    middleName = value;
}

void Worker::setMaskPossibleSpecs(QList<Specialization *> specs)
{
    this->maskPossibleSpecs = 0;
    for (QList<Specialization*>::const_iterator iter = specs.constBegin(); iter != specs.constEnd(); iter++){
        addPossibleSpecialization(*iter);
    }
}

QString Worker::getName() const
{
    return name;
}

void Worker::setName(const QString &value)
{
    name = value;
}

QString Worker::getLastName() const
{
    return lastName;
}

void Worker::setLastName(const QString &value)
{
    lastName = value;
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
    this->lastName = jsonObj["lastName"].toString();
    this->name = jsonObj["name"].toString();
    this->middleName = jsonObj["middleName"].toString();
    this->passportSeries = jsonObj["pSeries"].toString();
    this->passportNumber = jsonObj["pNumber"].toString();
    this->maskPossibleSpecs = jsonObj["mPS"].toString().toUInt();
    this->maskUsedSpecs = jsonObj["mUS"].toString().toUInt();
    this->isBusy = jsonObj["isBusy"].toBool();
}

void Worker::write(QJsonObject & jsonObj) const
{
    jsonObj["lastName"] = this->lastName;
    jsonObj["name"] = this->name;
    jsonObj["middleName"] = this->middleName;
    jsonObj["pSeries"] = this->passportSeries;
    jsonObj["pNumber"] = this->passportNumber;
    jsonObj["mPS"] = QString::number(this->maskPossibleSpecs);
    jsonObj["mUS"] = QString::number(this->maskUsedSpecs);
    jsonObj["isBusy"] = QJsonValue(this->isBusy);
}
