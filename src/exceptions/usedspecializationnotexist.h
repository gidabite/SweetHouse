#ifndef USEDSPECIALIZATIONNOTEXIST_H
#define USEDSPECIALIZATIONNOTEXIST_H

#include "specializationexception.h"

class UsedSpecializationNotExist : public SpecializationException
{
public:
    UsedSpecializationNotExist(Specialization *spec);
};


#endif // USEDSPECIALIZATIONNOTEXIST_H
