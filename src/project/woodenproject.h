#ifndef WOODENPROJECT_H
#define WOODENPROJECT_H

#include "project.h"

class WoodenProject : public Project
{
public:
    WoodenProject(QString nameProject, QString address, QString lastName, QString name, QString middleName, QString pSeries, QString pNumber);
};

#endif // WOODENPROJECT_H
