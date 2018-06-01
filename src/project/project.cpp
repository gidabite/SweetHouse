#include "project.h"

uint  Project::addProcess(QString name, uint stage, uint h)
{

    return  graph.addProcess(name, stage, h);
}

void Project::addLink(uint fromNode, uint toNode)
{
    graph.addEdge(fromNode, toNode);
}

QList<uint> Project::eval()
{
    return GraphExpression<Process>::algorithm(this->graph);
}

PSGraph *Project::getGraph()
{
    return &graph;
}

QString Project::getType() const
{
    return type;
}

void Project::setType(const QString &value)
{
    type = value;
}

uint Project::getId() const
{
    return id;
}

void Project::setId(const uint &value)
{
    id = value;
}

QString Project::getPassportNumber() const
{
    return passportNumber;
}

void Project::setPassportNumber(const QString &value)
{
    passportNumber = value;
}

QString Project::getPassportSeries() const
{
    return passportSeries;
}

void Project::setPassportSeries(const QString &value)
{
    passportSeries = value;
}

QString Project::getMiddleName() const
{
    return middleName;
}

void Project::setMiddleName(const QString &value)
{
    middleName = value;
}

QString Project::getName() const
{
    return name;
}

void Project::setName(const QString &value)
{
    name = value;
}

QString Project::getLastName() const
{
    return lastName;
}

void Project::setLastName(const QString &value)
{
    lastName = value;
}

QString Project::getAddress() const
{
    return address;
}

void Project::setAddress(const QString &value)
{
    address = value;
}

QString Project::getNameProject() const
{
    return nameProject;
}

void Project::setNameProject(const QString &value)
{
    nameProject = value;
}

void Project::addSlot(Specialization *spec)
{
    sls << Slot(spec);
    sls.last().setId(sls.length() - 1);
}

void Project::setWorker(Specialization *spec, Worker *worker) throw (WorkerIsBusyException, PossibleSpecializationNotExistExeption, UsedSpecializationAlreadyExist)
{
    for (QList<Slot>::iterator iter = sls.begin(); iter != sls.end(); iter++){
        if ((iter->getSpeceializationId() == spec->getId()) && (!(iter->getIsBusy()))){
            try {
                iter->setWorker(worker);
            } catch (WorkerIsBusyException ex){
                throw ex;
            } catch (PossibleSpecializationNotExistExeption ex){
                throw ex;
            }catch (UsedSpecializationAlreadyExist ex){
                throw ex;
            }
        }
    }
}

QList<Worker *> Project::getWorkersBySpecialization(Specialization *spec)
{
    QList<Worker *> temp;
    for (QList<Slot>::iterator iter = sls.begin(); iter != sls.end(); iter++){
        if (iter->getSpeceializationId() == spec->getId()){
            temp << iter->getWorker();
        }
    }
    return temp;
}


Slot *Project::getSlotById(uint id)
{
    return &(sls[id]);
}

void Project::read(const QJsonObject &jsonObj)
{
    QJsonArray jsonArray = jsonObj["slots"].toArray();
    foreach(QJsonValue jsonSlot, jsonArray)
    {
        Slot slot;
        slot.read(jsonSlot.toObject());
        sls << slot;
        sls.last().setId(sls.length() - 1);
    }
    this->nameProject = jsonObj["nameProject"].toString();
    this->address = jsonObj["address"].toString();
    this->lastName = jsonObj["lastName"].toString();
    this->name = jsonObj["name"].toString();
    this->middleName = jsonObj["middleName"].toString();
    this->passportSeries = jsonObj["passportSeries"].toString();
    this->passportNumber = jsonObj["passportNumber"].toString();
    this->type = jsonObj["type"].toString();
    graph.read(jsonObj["psgraph"].toObject());
    QJsonArray jsonArrayAlg = jsonObj["alg"].toArray();
    foreach(QJsonValue jsonNode, jsonArrayAlg)
    {
        this->algRes << ((jsonNode.toObject())["node"]).toString().toUInt();
    }
}

void Project::write(QJsonObject &obj) const
{
    QJsonArray jsonArray;
    for (QList<Slot>::const_iterator iter = sls.constBegin(); iter != sls.constEnd(); iter++){
        QJsonObject jsonSlot;
        iter->write(jsonSlot);
        jsonArray.append(jsonSlot);
    }
    QJsonObject jsonGraph;
    graph.write(jsonGraph);
    obj["psgraph"] = jsonGraph;
    obj["nameProject"] = this->nameProject;
    obj["slots"] = jsonArray;
    obj["address"] = this->address;
    obj["lastName"] = this->lastName;
    obj["name"] = this->name;
    obj["middleName"] = this->middleName;
    obj["passportSeries"] = this->passportSeries;
    obj["passportNumber"] = this->passportNumber;
    obj["type"] = this->type;
    QJsonArray jsonArrayAlg;
    for (QList<uint>::const_iterator iter = algRes.constBegin(); iter != algRes.constEnd(); iter++){
        QJsonObject jsonSlot;
        jsonSlot["node"] = QString::number(*iter);
        jsonArrayAlg.append(jsonSlot);
    }
    obj["alg"] = jsonArrayAlg;
}
