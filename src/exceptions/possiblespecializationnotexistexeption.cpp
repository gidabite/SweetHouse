#include "possiblespecializationnotexistexeption.h"



PossibleSpecializationNotExistExeption::PossibleSpecializationNotExistExeption(Specialization *spec)
{
    message = "The worker doesn't has this possible specialization: " + spec->getId();
}
