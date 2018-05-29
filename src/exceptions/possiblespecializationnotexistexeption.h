#ifndef POSSIBLESPECIALIZATIONNOTEXISTEXEPTION_H
#define POSSIBLESPECIALIZATIONNOTEXISTEXEPTION_H

#include "specializationexception.h"

class PossibleSpecializationNotExistExeption : public SpecializationException
{
public:
    PossibleSpecializationNotExistExeption(Specialization *spec);
};

#endif // POSSIBLESPECIALIZATIONNOTEXISTEXEPTION_H
