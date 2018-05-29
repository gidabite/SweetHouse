#ifndef AUTH_H
#define AUTH_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDataStream>

class Auth : public QObject
{
    Q_OBJECT
public:
    Auth();
private:
    const QString FILE_NAME = "auth.xml";
    const QString USER = "manager";
    const QString PASSWORD = "auth.xml";
    void create();
};

#endif // AUTH_H
