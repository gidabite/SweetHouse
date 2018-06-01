#include "editprojectwidjet.h"
#include "ui_editprojectwidjet.h"

EditProjectWidjet::EditProjectWidjet(Project * project, QWidget *parent) :
    EdirWidget(true, parent),
    ui(new Ui::EditProjectWidjet),
    project(project)
{
    ui->setupUi(this);
    this->id = project->getId();
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    redBrush.setColor(QColor(255,0,0));
    redBrush.setStyle(Qt::SolidPattern);
    greenBrush.setColor(QColor(0,255,0));
    greenBrush.setStyle(Qt::SolidPattern);
    blackpen.setColor(QColor(0,0,0));
    blackpen.setWidth(3);
    redpen.setColor(QColor(255,0,0));
    redpen.setWidth(3);
    if (project->getType() == "Wooden House")
        paintConcrete1();
}

EditProjectWidjet::~EditProjectWidjet()
{
    delete ui;
}

void EditProjectWidjet::paintConcrete1()
{
    Process* id1 = project->getGraph()->getNode(0);
    Process* id2 = project->getGraph()->getNode(1);
    Process* id3 = project->getGraph()->getNode(2);
    Process* id4 = project->getGraph()->getNode(3);
    Process* id5 = project->getGraph()->getNode(4);
    Process* id6 = project->getGraph()->getNode(5);
    Process* id7 = project->getGraph()->getNode(6);
    Process* id8 = project->getGraph()->getNode(7);
    Process* id9 = project->getGraph()->getNode(8);
    Process* id10 = project->getGraph()->getNode(9);
    Process* id11 = project->getGraph()->getNode(10);
    Process* id12 = project->getGraph()->getNode(11);
    Process* id13 = project->getGraph()->getNode(12);
    Process* id14 = project->getGraph()->getNode(13);
    Process* id15 = project->getGraph()->getNode(14);
    Process* id16 = project->getGraph()->getNode(15);
    Process* id17 = project->getGraph()->getNode(16);
    Process* id18 = project->getGraph()->getNode(17);
    Process* id19 = project->getGraph()->getNode(18);
    Process* id20 = project->getGraph()->getNode(19);
    Process* id21 = project->getGraph()->getNode(20);
    Process* id22 = project->getGraph()->getNode(21);

    paintEdge(25,135,100,135, redpen);

    paintEdge(100,135,175,35, blackpen);
    paintEdge(100,135,175,235, redpen);

    paintEdge(175,35,250,135, blackpen);
    paintEdge(175, 235, 250,135, redpen);

    paintEdge(250,135, 325,35, blackpen);
    paintEdge(250,135, 325,135, blackpen);
    paintEdge(250,135, 325,235, redpen);

    paintEdge(325, 35, 400,35, blackpen);
    paintEdge(325, 135, 400,135, blackpen);
    paintEdge(325, 235, 499,235, redpen);

    paintEdge(400, 35, 475,35, blackpen);
    paintEdge(400, 135, 475,135, blackpen);
    paintEdge(400, 235, 475,235, redpen);

    paintEdge(475, 35, 550,35, blackpen);
    paintEdge(475, 135, 550,135, blackpen);
    paintEdge(475, 235, 550,235, redpen);

    paintEdge(550, 35, 625,135, blackpen);
    paintEdge(550, 135, 625,135, blackpen);
    paintEdge(550, 235, 625,135, redpen);

    paintEdge(625, 135, 700,35, blackpen);
    paintEdge(625, 135, 700,235, redpen);

    paintEdge(700, 35, 775,135, blackpen);
    paintEdge(700, 235, 775,135, redpen);

    paintEdge(775, 135, 850,135, redpen);

    paintNode(id1,13,123,25);
    paintNode(id2,88, 123, 25);
    paintNode(id3,163, 23, 25);
    paintNode(id4,163, 223, 25);
    paintNode(id5,238, 123, 25);

    paintNode(id6,313, 23, 25);
    paintNode(id7,313, 123, 25);
    paintNode(id8,313, 223, 25);


    paintNode(id9,388, 23, 25);
    paintNode(id10,388, 123, 25);
    paintNode(id11, 388, 223, 25);


    paintNode(id12,463, 23, 25);
    paintNode(id13,463, 123, 25);
    paintNode(id14,463, 223, 25);


    paintNode(id15,538, 23, 25);
    paintNode(id16,538, 123, 25);
    paintNode(id17,538, 223, 25);

    paintNode(id18,613, 123, 25);


    paintNode(id19,688, 23, 25);
    paintNode(id20,688, 223, 25);

    paintNode(id21,763, 123, 25);

    paintNode(id22,838, 123, 25);

    //if (id1->getStatus() == 0)
    //nodes << scene->addEllipse(25,123,25,25,blackpen, redBrush);
}

void EditProjectWidjet::paintNode(Process *pr, int x, int y, int r)
{
    if (pr->getStatus() == 0)
        nodes << scene->addEllipse(x,y,r,r,blackpen, QBrush(QColor(128,128,128)));
    if (pr->getStatus() == 1)
        nodes << scene->addEllipse(x,y,r,r,blackpen, redBrush);
    if (pr->getStatus() == 2)
        nodes << scene->addEllipse(x,y,r,r,blackpen, greenBrush);
}

void EditProjectWidjet::paintEdge(int x1, int y1, int x2, int y2, QPen &pen)
{
    edges << scene->addLine(x1,y1,x2,y2, pen);
}


