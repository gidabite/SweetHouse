#include "process.h"

Process::Process()
{

}

void Process::addSlot(Slot slot)
{
    sls << slot;
}

uint Process::getIdStage() const
{
    return idStage;
}

void Process::setIdStage(const uint &value)
{
    idStage = value;
}

uint Process::getStatus() const
{
    return status;
}

void Process::setStatus(const uint &value)
{
    status = value;
}

void Process::read(const QJsonObject &jsonObj)
{
    this->idStage = jsonObj["idStage"].toString().toUInt();
    this->status = jsonObj["status"].toString().toUInt();
    this->h = jsonObj["h"].toString().toUInt();
    this->name = jsonObj["name"].toString();
    QJsonArray jsonArray = jsonObj["slots"].toArray();
    foreach(QJsonValue jsonSlot, jsonArray)
    {
        Slot slot;
        slot.read(jsonSlot.toObject());
        sls << slot;
        sls.last().setId(sls.length() - 1);
    }
}

void Process::write(QJsonObject &obj) const
{
    obj["name"] = this->name;
    obj["status"] = QString::number(this->status);
    obj["h"] = QString::number(this->h);
    obj["idStage"] = QString::number(this->idStage);
    QJsonArray jsonArray;
    for (QList<Slot>::const_iterator iter = sls.constBegin(); iter != sls.constEnd(); iter++){
        QJsonObject jsonSlot;
        iter->write(jsonSlot);
        jsonArray.append(jsonSlot);
    }
    obj["slots"] = jsonArray;
}

uint Process::getData() const
{
    return this->h;
}

