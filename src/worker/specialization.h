#ifndef SPECIALIZATION_H
#define SPECIALIZATION_H

#include <QTranslator>
#include "../singleton.h"

class Specialization {
public:
    uint getId() const;
    QString getSpecializationName() const;
protected:
    Specialization(uint id, QString sName);
    Specialization();
    uint id;
    QString specializationName;
};

class EmptySpecialization: public Specialization, public Singleton<EmptySpecialization>{
    friend class Singleton<EmptySpecialization>;
private:
    EmptySpecialization():Specialization(0, QTranslator::tr("Empty")){}
};
class Surveyor: public Specialization, public Singleton<Surveyor>{
    friend class Singleton<Surveyor>;
    Surveyor():Specialization(1, QTranslator::tr("Surveuor")){}
};
class Foreman: public Specialization, public Singleton<Foreman>{
    friend class Singleton<Foreman>;
    Foreman():Specialization(2, QTranslator::tr("Foreman")){}
};
class Builder: public Specialization, public Singleton<Builder>{
    friend class Singleton<Builder>;
private:
    Builder():Specialization(4, QTranslator::tr("Builder")){}
};
class Roofer: public Specialization, public Singleton<Roofer>{
    friend class Singleton<Roofer>;
    Roofer():Specialization(8, QTranslator::tr("Roofer")){}
};
class Electrician: public Specialization, public Singleton<Electrician>{
    friend class Singleton<Electrician>;
    Electrician():Specialization(16, QTranslator::tr("Electrician")){}
};
class Plumber: public Specialization, public Singleton<Plumber>{
    friend class Singleton<Plumber>;
    Plumber():Specialization(32, QTranslator::tr("Plumber")){}
};
class Manager: public Specialization, public Singleton<Manager>{
    friend class Singleton<Manager>;
    Manager():Specialization(64, QTranslator::tr("Manager")){}
};

#endif // SPECIALIZATION_H
