#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include "singleton.h"
#include "serialization/serializable.h"
#include "project/woodenproject.h"

class ProjectManager: public Singleton<ProjectManager>, public Serializable
{
    friend class Singleton<ProjectManager>;
public:
    Project *addConcreteProject1(QString nameProject, QString address, QString lastName, QString name, QString middleName, QString pSeries, QString pNumber);
    Project *getProjectById(uint id);
    QList<Project> getProjects() const;
    void deleteProject(uint id);
private:
    ProjectManager();
    QList<Project> projects;

    // Serializable interface
public:
    void read(const QJsonObject &jsonObj);
    void write(QJsonObject &obj) const;
};

#endif // PROJECTMANAGER_H
