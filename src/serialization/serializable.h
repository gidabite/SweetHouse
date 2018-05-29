#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <QJsonObject>

class Serializable
{
public:
    virtual void read(const QJsonObject &jsonObj) = 0;
    virtual void write(QJsonObject& obj) const = 0;
    virtual ~Serializable() = 0;
};

#endif // SERIALIZABLE_H
