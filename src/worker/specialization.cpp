#include "specialization.h"

Specialization::Specialization(uint id, QString sName): id(id), specializationName(sName){}

uint Specialization::getId() const{
    return id;
}

QString Specialization::getSpecializationName() const
{
    return specializationName;
}
