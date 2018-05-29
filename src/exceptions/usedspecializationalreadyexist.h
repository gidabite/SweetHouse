#ifndef USEDSPECIALIZATIONALREADYEXIST_H
#define USEDSPECIALIZATIONALREADYEXIST_H

#include "specializationexception.h"

class UsedSpecializationAlreadyExist : public SpecializationException
{
public:
    UsedSpecializationAlreadyExist(Specialization *spec);
};

#endif // USEDSPECIALIZATIONALREADYEXIST_H
