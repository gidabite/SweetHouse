#include "project.h"

Project::Project()
{

}

uint Project::addStage(QString name)
{
    return graph.addStage(name);
}

uint Project::addProcess(QString name, uint stage)
{
    return  graph.addProcess(name, stage);
}

void Project::addLink(uint fromNode, uint toNode)
{
    graph.addEdge(fromNode, toNode);
}

void Project::addSlot(Specialization *spec)
{
    sls << Slot(spec);
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

void Project::read(const QJsonObject &jsonObj)
{
    QJsonArray jsonArray = jsonObj["slots"].toArray();
    foreach(QJsonValue jsonSlot, jsonArray)
    {
        Slot slot;
        slot.read(jsonSlot.toObject());
        sls << slot;
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
    obj["name"] = this->name;
    obj["slots"] = jsonArray;
}
