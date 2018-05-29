#include "usedspecializationnotexist.h"

UsedSpecializationNotExist::UsedSpecializationNotExist(Specialization *spec)
{
    message = "The worker already has this used specialization: " + spec->getId();
}

