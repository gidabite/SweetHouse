#include "PossibleSpecAEExeption.h"

PossibleSpecializationAlreadyExistExeption::PossibleSpecializationAlreadyExistExeption(Specialization *spec)
{
    message = "The worker already has this possible specialization: " + spec->getId();
}
