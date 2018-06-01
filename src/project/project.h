#ifndef PROJECT_H
#define PROJECT_H

#include "../graph/psgraph.h"
#include "../worker/worker.h"
#include "../worker/slot.h"
#include "graph/graphexpression.h"
#include <QString>
#include <QList>

class Project: public Serializable
{
public:
    Project(){};
    Project(QString nameProject, QString address, QString lastName, QString name, QString middleName, QString pSeries, QString pNumber):
        nameProject(nameProject),address(address), lastName(lastName), name(name), middleName(middleName), passportSeries(pSeries), passportNumber(pNumber){};
    void setWorker(Specialization *spec, Worker *worker) throw (WorkerIsBusyException, PossibleSpecializationNotExistExeption, UsedSpecializationAlreadyExist);
    QList<Worker *> getWorkersBySpecialization(Specialization *spec);
    Slot * getSlotById(uint id);

    void addSlot(Specialization *spec);
    uint addProcess(QString name, uint stage, uint h);
    void addLink(uint fromNode, uint toNode);
    QList<uint> eval();
protected:
    PSGraph graph;
    QString nameProject;
    QString address;
    QString lastName;
    QString name;
    QString middleName;
    QString passportSeries;
    QString passportNumber;
    QList<Slot> sls;
    QList<uint> F;
    QString type;
    QList<uint> algRes;
    uint id;
    // Serializable interface
public:
    void read(const QJsonObject &jsonObj);
    void write(QJsonObject &obj) const;
    QString getNameProject() const;
    void setNameProject(const QString &value);
    QString getAddress() const;
    void setAddress(const QString &value);
    QString getLastName() const;
    void setLastName(const QString &value);
    QString getName() const;
    void setName(const QString &value);
    QString getMiddleName() const;
    void setMiddleName(const QString &value);
    QString getPassportSeries() const;
    void setPassportSeries(const QString &value);
    QString getPassportNumber() const;
    void setPassportNumber(const QString &value);
    uint getId() const;
    void setId(const uint &value);
    QString getType() const;
    void setType(const QString &value);
    PSGraph* getGraph();
};

#endif // PROJECT_H
