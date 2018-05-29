#ifndef POSSIBLESPECAEEEXCEPTION_H
#define POSSIBLESPECAEEEXCEPTION_H

#include "specializationexception.h"

class PossibleSpecializationAlreadyExistExeption : public SpecializationException
{
public:
    PossibleSpecializationAlreadyExistExeption(Specialization *spec);
};

#endif // POSSIBLESPECAEEEXCEPTION_H
