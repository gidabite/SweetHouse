#ifndef SPECIALIZATIONEXCEPTION_H
#define SPECIALIZATIONEXCEPTION_H

#include <QException>
#include "../worker/specialization.h"
#include <QString>

class SpecializationException : public QException
{
public:
    QString getMessage();
protected:
    QString message;
};

#endif // SPECIALIZATIONEXCEPTION_H
