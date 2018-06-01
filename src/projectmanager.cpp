#include "projectmanager.h"

Project *ProjectManager::addConcreteProject1(QString nameProject, QString address, QString lastName, QString name, QString middleName, QString pSeries, QString pNumber)
{
    Project pr(nameProject, address, lastName, name, middleName, pSeries, pNumber);
    pr.setType("Wooden House");
    pr.addSlot(Manager::instance());
    pr.addSlot(Foreman::instance());
    pr.addSlot(Surveyor::instance());
    pr.addSlot(Builder::instance());
    pr.addSlot(Builder::instance());
    pr.addSlot(Builder::instance());
    pr.addSlot(Electrician::instance());
    pr.addSlot(Electrician::instance());
    pr.addSlot(Roofer::instance());
    pr.addSlot(Plumber::instance());

    uint id1 = pr.addProcess("Purchase of materials", 0, 56);
    pr.getGraph()->getNode(id1)->addSlot(Manager::instance());
    pr.getGraph()->getNode(id1)->setStatus(1);
    uint id2 = pr.addProcess("Preparation of the area", 1, 16);
    pr.getGraph()->getNode(id2)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id2)->addSlot(Surveyor::instance());
    pr.getGraph()->getNode(id2)->addSlot(Builder::instance());
    pr.getGraph()->getNode(id2)->addSlot(Builder::instance());
    pr.getGraph()->getNode(id2)->addSlot(Builder::instance());
    pr.addLink(id1, id2);
    uint id3 = pr.addProcess("Filling the foundation", 1, 48);
    pr.getGraph()->getNode(id3)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id3)->addSlot(Builder::instance());
    pr.getGraph()->getNode(id3)->addSlot(Builder::instance());
    pr.addLink(id2, id3);
    uint id4 = pr.addProcess("Preparation of wood for a floor carcass of 1 floor", 1, 32);
    pr.getGraph()->getNode(id4)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id4)->addSlot(Builder::instance());
    pr.addLink(id2, id4);
    uint id5 = pr.addProcess("Laying the frame of the first floor", 1, 8);
    pr.getGraph()->getNode(id5)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id5)->addSlot(Builder::instance());
    pr.getGraph()->getNode(id5)->addSlot(Builder::instance());
    pr.getGraph()->getNode(id5)->addSlot(Builder::instance());
    pr.addLink(id3, id5);
    pr.addLink(id4, id5);
    uint id6 = pr.addProcess("Floor installation of 1 room", 2, 2);
    pr.getGraph()->getNode(id6)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id6)->addSlot(Builder::instance());
    pr.addLink(id5, id6);
    uint id7 = pr.addProcess("Floor installation of 2 room", 2, 2);
    pr.getGraph()->getNode(id7)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id7)->addSlot(Builder::instance());
    pr.addLink(id5, id7);
    uint id8 = pr.addProcess("Floor installation of 3 room", 2, 2);
    pr.getGraph()->getNode(id8)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id8)->addSlot(Builder::instance());
    pr.addLink(id5, id8);
    uint id9 = pr.addProcess("Kitchen floor installation", 2, 2);
    pr.getGraph()->getNode(id9)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id9)->addSlot(Builder::instance());
    pr.addLink(id6, id9);
    uint id10 = pr.addProcess("Laying the floor of the bathroom", 2, 2);
    pr.getGraph()->getNode(id10)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id10)->addSlot(Builder::instance());
    pr.addLink(id7, id10);
    uint id11 = pr.addProcess("Laying the floor of the hall", 2, 2);
    pr.getGraph()->getNode(id11)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id11)->addSlot(Builder::instance());
    pr.addLink(id8, id11);

    uint id12 = pr.addProcess("Building of walls of 1 room", 2, 4);
    pr.getGraph()->getNode(id12)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id12)->addSlot(Builder::instance());
    pr.addLink(id9, id12);
    uint id13 = pr.addProcess("Building of walls of 2 room", 2, 4);
    pr.getGraph()->getNode(id13)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id13)->addSlot(Builder::instance());
    pr.addLink(id10, id13);
    uint id14 = pr.addProcess("Building of walls of 3 room", 2, 6);
    pr.getGraph()->getNode(id14)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id14)->addSlot(Builder::instance());
    pr.addLink(id11, id14);
    uint id15 = pr.addProcess("Building of walls of kitchen room", 2, 4);
    pr.getGraph()->getNode(id15)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id15)->addSlot(Builder::instance());
    pr.addLink(id12, id15);
    uint id16 = pr.addProcess("Building of walls of 1 bathroom", 2, 4);
    pr.getGraph()->getNode(id16)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id16)->addSlot(Builder::instance());
    pr.addLink(id13, id16);
    uint id17 = pr.addProcess("Building of walls of hall room", 2, 4);
    pr.getGraph()->getNode(id17)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id17)->addSlot(Builder::instance());
    pr.addLink(id14, id17);
    uint id18 = pr.addProcess("Roof construction", 2, 18);
    pr.getGraph()->getNode(id6)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id6)->addSlot(Roofer::instance());
    pr.addLink(id15, id18);
    pr.addLink(id16, id18);
    pr.addLink(id17, id18);
    uint id19 = pr.addProcess("Plumbing installation", 3, 17);
    pr.getGraph()->getNode(id19)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id19)->addSlot(Plumber::instance());
    pr.addLink(id18, id19);
    uint id20 = pr.addProcess("Electrical installation works", 3, 21);
    pr.getGraph()->getNode(id20)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id20)->addSlot(Electrician::instance());
    pr.addLink(id18, id20);
    uint id21 = pr.addProcess("Commissioning", 3, 2);
    pr.getGraph()->getNode(id21)->addSlot(Foreman::instance());
    pr.getGraph()->getNode(id21)->addSlot(Manager::instance());
    pr.addLink(id19, id21);
    pr.addLink(id20, id21);
    uint id22 = pr.addProcess("Complete", 4, 0);
    pr.getGraph()->getNode(id22)->addSlot(Manager::instance());
    pr.addLink(id21, id22);
    pr.setId(projects.length());
    projects << pr;
    uint max;
    pr.eval();
    return &(pr);
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
