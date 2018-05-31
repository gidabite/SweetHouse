#include "projectmanager.h"

Project *ProjectManager::addConcreteProject1(QString nameProject, QString address, QString lastName, QString name, QString middleName, QString pSeries, QString pNumber)
{
    projects << Project(nameProject, address, lastName, name, middleName, pSeries, pNumber);
    projects.last().setType("Wooden House");
    projects.last().addSlot(Manager::instance());
    projects.last().addSlot(Foreman::instance());
    projects.last().addSlot(Surveyor::instance());
    projects.last().addSlot(Builder::instance());
    projects.last().addSlot(Builder::instance());
    projects.last().addSlot(Builder::instance());
    projects.last().addSlot(Electrician::instance());
    projects.last().addSlot(Electrician::instance());
    projects.last().addSlot(Roofer::instance());
    projects.last().addSlot(Plumber::instance());

    uint id1 = projects.last().addProcess("Purchase of materials", 0, 56);
    projects.last().getGraph()->getNode(id1)->addSlot(Manager::instance());
    uint id2 = projects.last().addProcess("Preparation of the area", 1, 16);
    projects.last().getGraph()->getNode(id2)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id2)->addSlot(Surveyor::instance());
    projects.last().getGraph()->getNode(id2)->addSlot(Builder::instance());
    projects.last().getGraph()->getNode(id2)->addSlot(Builder::instance());
    projects.last().getGraph()->getNode(id2)->addSlot(Builder::instance());
    projects.last().addLink(id1, id2);
    uint id3 = projects.last().addProcess("Filling the foundation", 1, 48);
    projects.last().getGraph()->getNode(id3)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id3)->addSlot(Builder::instance());
    projects.last().getGraph()->getNode(id3)->addSlot(Builder::instance());
    projects.last().addLink(id2, id3);
    uint id4 = projects.last().addProcess("Preparation of wood for a floor carcass of 1 floor", 1, 32);
    projects.last().getGraph()->getNode(id4)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id4)->addSlot(Builder::instance());
    projects.last().addLink(id2, id4);
    uint id5 = projects.last().addProcess("Laying the frame of the first floor", 1, 8);
    projects.last().getGraph()->getNode(id5)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id5)->addSlot(Builder::instance());
    projects.last().getGraph()->getNode(id5)->addSlot(Builder::instance());
    projects.last().getGraph()->getNode(id5)->addSlot(Builder::instance());
    projects.last().addLink(id3, id5);
    projects.last().addLink(id4, id5);
    uint id6 = projects.last().addProcess("Floor installation of 1 room", 2, 2);
    projects.last().getGraph()->getNode(id6)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id6)->addSlot(Builder::instance());
    projects.last().addLink(id5, id6);
    uint id7 = projects.last().addProcess("Floor installation of 2 room", 2, 2);
    projects.last().getGraph()->getNode(id7)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id7)->addSlot(Builder::instance());
    projects.last().addLink(id5, id7);
    uint id8 = projects.last().addProcess("Floor installation of 3 room", 2, 2);
    projects.last().getGraph()->getNode(id8)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id8)->addSlot(Builder::instance());
    projects.last().addLink(id5, id8);
    uint id9 = projects.last().addProcess("Kitchen floor installation", 2, 2);
    projects.last().getGraph()->getNode(id9)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id9)->addSlot(Builder::instance());
    projects.last().addLink(id6, id9);
    uint id10 = projects.last().addProcess("Laying the floor of the bathroom", 2, 2);
    projects.last().getGraph()->getNode(id10)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id10)->addSlot(Builder::instance());
    projects.last().addLink(id7, id10);
    uint id11 = projects.last().addProcess("Laying the floor of the hall", 2, 2);
    projects.last().getGraph()->getNode(id11)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id11)->addSlot(Builder::instance());
    projects.last().addLink(id8, id11);

    uint id12 = projects.last().addProcess("Building of walls of 1 room", 2, 4);
    projects.last().getGraph()->getNode(id12)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id12)->addSlot(Builder::instance());
    projects.last().addLink(id9, id12);
    uint id13 = projects.last().addProcess("Building of walls of 2 room", 2, 4);
    projects.last().getGraph()->getNode(id13)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id13)->addSlot(Builder::instance());
    projects.last().addLink(id10, id13);
    uint id14 = projects.last().addProcess("Building of walls of 3 room", 2, 6);
    projects.last().getGraph()->getNode(id14)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id14)->addSlot(Builder::instance());
    projects.last().addLink(id11, id14);
    uint id15 = projects.last().addProcess("Building of walls of kitchen room", 2, 4);
    projects.last().getGraph()->getNode(id15)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id15)->addSlot(Builder::instance());
    projects.last().addLink(id12, id15);
    uint id16 = projects.last().addProcess("Building of walls of 1 bathroom", 2, 4);
    projects.last().getGraph()->getNode(id16)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id16)->addSlot(Builder::instance());
    projects.last().addLink(id13, id16);
    uint id17 = projects.last().addProcess("Building of walls of hall room", 2, 4);
    projects.last().getGraph()->getNode(id17)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id17)->addSlot(Builder::instance());
    projects.last().addLink(id4, id17);
    uint id18 = projects.last().addProcess("Roof construction", 2, 18);
    projects.last().getGraph()->getNode(id6)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id6)->addSlot(Roofer::instance());
    projects.last().addLink(id15, id18);
    projects.last().addLink(id16, id18);
    projects.last().addLink(id17, id18);
    uint id19 = projects.last().addProcess("Plumbing installation", 3, 17);
    projects.last().getGraph()->getNode(id19)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id19)->addSlot(Plumber::instance());
    projects.last().addLink(id18, id19);
    uint id20 = projects.last().addProcess("Electrical installation works", 3, 21);
    projects.last().getGraph()->getNode(id20)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id20)->addSlot(Electrician::instance());
    projects.last().addLink(id18, id20);
    uint id21 = projects.last().addProcess("Commissioning", 3, 2);
    projects.last().getGraph()->getNode(id21)->addSlot(Foreman::instance());
    projects.last().getGraph()->getNode(id21)->addSlot(Manager::instance());
    projects.last().addLink(id19, id21);
    projects.last().addLink(id20, id21);
    uint id22 = projects.last().addProcess("Complete", 4, 0);
    projects.last().getGraph()->getNode(id22)->addSlot(Manager::instance());
    projects.last().addLink(id21, id22);
    projects.last().setId(projects.length() - 1);
    return &(projects.last());
}

Project *ProjectManager::getProjectById(uint id)
{
    return &(projects[id]);
}

QList<Project> ProjectManager::getProjects() const
{
    return projects;
}

void ProjectManager::deleteProject(uint id)
{
    projects.removeAt(id);
}

ProjectManager::ProjectManager()
{
    QFile wFile("projects.json");
    if (wFile.exists()){
        if (wFile.open(QIODevice::ReadOnly))
        {
            QString ser = QString(wFile.readAll());
            Serializer<ProjectManager>::parse(ser, *this);
            wFile.close();
        }
    }
}

void ProjectManager::read(const QJsonObject &jsonObj)
{
    QJsonArray jsonArray = jsonObj["projects"].toArray();
    foreach(QJsonValue jsonProject, jsonArray)
    {
        Project project;
        project.read(jsonProject.toObject());
        projects << project;
        projects.last().setId(projects.length() - 1);
    }
}

void ProjectManager::write(QJsonObject &obj) const
{
    QJsonArray jsonArray;
    for (QList<Project>::const_iterator iter = projects.constBegin(); iter != projects.constEnd(); iter++){
        QJsonObject jsonProject;
        iter->write(jsonProject);
        jsonArray.append(jsonProject);
    }
    obj["projects"] = jsonArray;
}
