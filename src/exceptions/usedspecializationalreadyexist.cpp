#include "usedspecializationalreadyexist.h"

UsedSpecializationAlreadyExist::UsedSpecializationAlreadyExist(Specialization *spec)
{
    message = "The worker alreasy has this used specialization: " + spec->getId();
}

