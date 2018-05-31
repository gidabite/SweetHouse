#include "woodenproject.h"

WoodenProject::WoodenProject(QString nameProject, QString address, QString lastName, QString name, QString middleName, QString pSeries, QString pNumber):
    Project(nameProject, address, lastName, name, middleName, pSeries, pNumber)
{
    this->addSlot(Manager::instance());
    this->addSlot(Foreman::instance());
    this->addSlot(Surveyor::instance());
    this->addSlot(Builder::instance());
    this->addSlot(Builder::instance());
    this->addSlot(Builder::instance());
    this->addSlot(Electrician::instance());
    this->addSlot(Electrician::instance());
    this->addSlot(Roofer::instance());
    this->addSlot(Plumber::instance());

    uint id1 = this->addProcess("Purchase of materials", 0, 56);
    this->graph.getNode(id1)->addSlot(Manager::instance());
    uint id2 = this->addProcess("Preparation of the area", 1, 16);
    this->graph.getNode(id2)->addSlot(Foreman::instance());
    this->graph.getNode(id2)->addSlot(Surveyor::instance());
    this->graph.getNode(id2)->addSlot(Builder::instance());
    this->graph.getNode(id2)->addSlot(Builder::instance());
    this->graph.getNode(id2)->addSlot(Builder::instance());
    this->addLink(id1, id2);
    uint id3 = this->addProcess("Filling the foundation", 1, 48);
    this->graph.getNode(id3)->addSlot(Foreman::instance());
    this->graph.getNode(id3)->addSlot(Builder::instance());
    this->graph.getNode(id3)->addSlot(Builder::instance());
    this->addLink(id2, id3);
    uint id4 = this->addProcess("Preparation of wood for a floor carcass of 1 floor", 1, 32);
    this->graph.getNode(id4)->addSlot(Foreman::instance());
    this->graph.getNode(id4)->addSlot(Builder::instance());
    this->addLink(id2, id4);
    uint id5 = this->addProcess("Laying the frame of the first floor", 1, 8);
    this->graph.getNode(id5)->addSlot(Foreman::instance());
    this->graph.getNode(id5)->addSlot(Builder::instance());
    this->graph.getNode(id5)->addSlot(Builder::instance());
    this->graph.getNode(id5)->addSlot(Builder::instance());
    this->addLink(id3, id5);
    this->addLink(id4, id5);
    uint id6 = this->addProcess("Floor installation of 1 room", 2, 2);
    this->graph.getNode(id6)->addSlot(Foreman::instance());
    this->graph.getNode(id6)->addSlot(Builder::instance());
    this->addLink(id5, id6);
    uint id7 = this->addProcess("Floor installation of 2 room", 2, 2);
    this->graph.getNode(id7)->addSlot(Foreman::instance());
    this->graph.getNode(id7)->addSlot(Builder::instance());
    this->addLink(id5, id7);
    uint id8 = this->addProcess("Floor installation of 3 room", 2, 2);
    this->graph.getNode(id8)->addSlot(Foreman::instance());
    this->graph.getNode(id8)->addSlot(Builder::instance());
    this->addLink(id5, id8);
    uint id9 = this->addProcess("Kitchen floor installation", 2, 2);
    this->graph.getNode(id9)->addSlot(Foreman::instance());
    this->graph.getNode(id9)->addSlot(Builder::instance());
    this->addLink(id6, id9);
    uint id10 = this->addProcess("Laying the floor of the bathroom", 2, 2);
    this->graph.getNode(id10)->addSlot(Foreman::instance());
    this->graph.getNode(id10)->addSlot(Builder::instance());
    this->addLink(id7, id10);
    uint id11 = this->addProcess("Laying the floor of the hall", 2, 2);
    this->graph.getNode(id11)->addSlot(Foreman::instance());
    this->graph.getNode(id11)->addSlot(Builder::instance());
    this->addLink(id8, id11);

    uint id12 = this->addProcess("Building of walls of 1 room", 2, 4);
    this->graph.getNode(id12)->addSlot(Foreman::instance());
    this->graph.getNode(id12)->addSlot(Builder::instance());
    this->addLink(id9, id12);
    uint id13 = this->addProcess("Building of walls of 2 room", 2, 4);
    this->graph.getNode(id13)->addSlot(Foreman::instance());
    this->graph.getNode(id13)->addSlot(Builder::instance());
    this->addLink(id10, id13);
    uint id14 = this->addProcess("Building of walls of 3 room", 2, 6);
    this->graph.getNode(id14)->addSlot(Foreman::instance());
    this->graph.getNode(id14)->addSlot(Builder::instance());
    this->addLink(id11, id14);
    uint id15 = this->addProcess("Building of walls of kitchen room", 2, 4);
    this->graph.getNode(id15)->addSlot(Foreman::instance());
    this->graph.getNode(id15)->addSlot(Builder::instance());
    this->addLink(id12, id15);
    uint id16 = this->addProcess("Building of walls of 1 bathroom", 2, 4);
    this->graph.getNode(id16)->addSlot(Foreman::instance());
    this->graph.getNode(id16)->addSlot(Builder::instance());
    this->addLink(id13, id16);
    uint id17 = this->addProcess("Building of walls of hall room", 2, 4);
    this->graph.getNode(id17)->addSlot(Foreman::instance());
    this->graph.getNode(id17)->addSlot(Builder::instance());
    this->addLink(id4, id17);
    uint id18 = this->addProcess("Roof construction", 2, 18);
    this->graph.getNode(id6)->addSlot(Foreman::instance());
    this->graph.getNode(id6)->addSlot(Roofer::instance());
    this->addLink(id15, id18);
    this->addLink(id16, id18);
    this->addLink(id17, id18);
    uint id19 = this->addProcess("Plumbing installation", 3, 17);
    this->graph.getNode(id19)->addSlot(Foreman::instance());
    this->graph.getNode(id19)->addSlot(Plumber::instance());
    this->addLink(id18, id19);
    uint id20 = this->addProcess("Electrical installation works", 3, 21);
    this->graph.getNode(id20)->addSlot(Foreman::instance());
    this->graph.getNode(id20)->addSlot(Electrician::instance());
    this->addLink(id18, id20);
    uint id21 = this->addProcess("Commissioning", 3, 2);
    this->graph.getNode(id21)->addSlot(Foreman::instance());
    this->graph.getNode(id21)->addSlot(Manager::instance());
    this->addLink(id19, id21);
    this->addLink(id20, id21);
    uint id22 = this->addProcess("Complete", 4, 0);
    this->graph.getNode(id22)->addSlot(Manager::instance());
    this->addLink(id21, id22);



}
