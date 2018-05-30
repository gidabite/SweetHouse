#include "project.h"

Project::Project()
{

}

uint Project::addProcess(QString name, uint stage, uint h)
{
    return  graph.addProcess(name, stage, h);
}

void Project::addLink(uint fromNode, uint toNode)
{
    graph.addEdge(fromNode, toNode);
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
    this->name = jsonObj["name"].toString();
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
    obj["name"] = this->name;
    obj["slots"] = jsonArray;
}
