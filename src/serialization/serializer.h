#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <QString>
#include <QJsonDocument>
#include "serializable.h"

template <class T>
class Serializer
{
public:
    static QString serialize(const Serializable &obj){
        QJsonObject jsonObj;
        obj.write(jsonObj);
        QJsonDocument doc(jsonObj);
        QString result(doc.toJson(QJsonDocument::Indented));
        return result;
    }

   static void parse(const QString &json, T &jsonSerializable){
       QJsonDocument document = QJsonDocument::fromJson(json.toUtf8());
       // The document wrap a jsonObject
       QJsonObject jsonObj = document.object();
       jsonSerializable.read(jsonObj);
   }

private:

   PersonJsonSerializer();
};

#endif // SERIALIZER_H
