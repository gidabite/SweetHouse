#ifndef WORKER_H
#define WORKER_H

#include <QException>
#include "specialization.h"
#include "../exceptions/specializations.h"
#include "../serialization/serializable.h"

class Worker: public Serializable{
public:
    Worker();
    Worker(QString lName,QString name, QString mName, QString pSerias, QString pNumber, QList<Specialization*> specs);
    ~Worker();
    void addPossibleSpecialization(Specialization *posibleSpec) throw(PossibleSpecializationAlreadyExistExeption);
    void removePossibleSpecialization(Specialization *posibleSpec) throw(PossibleSpecializationNotExistExeption);
    bool isExistPossibleSpecialization(Specialization *posibleSpec);

    void addUsedSpecialization(Specialization *spec) throw(PossibleSpecializationNotExistExeption, UsedSpecializationAlreadyExist);
    void removeUsedSpecialization(Specialization *spec) throw(UsedSpecializationNotExist);
    bool isExistUsedSpecializtion(Specialization* spec);

    bool getIsBusy() const;
    void setIsBusy(bool value);
    QString getPassportNumber() const;
    void setPassportNumber(const QString &value);

    QString getPassportSeries() const;
    void setPassportSeries(const QString &value);

private:
    bool isBusy;
    uint maskPossibleSpecs;
    uint maskUsedSpecs;
    QString lastName;
    QString name;
    QString middleName;
    QString passportSeries;
    QString passportNumber;
    uint id;

    // Serializable interface
public:
    void read(const QJsonObject &jsonObj);
    QJsonObject & write() const;
    void write(QJsonObject &obj) const;
    uint getId() const;
    void setId(const uint &value);
    QString getLastName() const;
    void setLastName(const QString &value);
    QString getName() const;
    void setName(const QString &value);
    QString getMiddleName() const;
    void setMiddleName(const QString &value);
    void setMaskPossibleSpecs(QList<Specialization*> specs);
};


#endif // WORKER_H
