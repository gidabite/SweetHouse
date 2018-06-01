#ifndef EDITPROJECTWIDJET_H
#define EDITPROJECTWIDJET_H

#include "edirwidget.h"
#include "project/project.h"
#include <QGraphicsScene>

namespace Ui {
class EditProjectWidjet;
}
class Arrow
{
public:
    QGraphicsLineItem *start;
    QGraphicsLineItem *end;
    QGraphicsLineItem *leftPlumage;
    QGraphicsLineItem *rightPlumage;
};

class EditProjectWidjet : public EdirWidget
{
    Q_OBJECT

public:
    explicit EditProjectWidjet(Project * project, QWidget *parent = 0);
    ~EditProjectWidjet();

signals:
    void deleteProject(uint);
private:
    Ui::EditProjectWidjet *ui;
    QGraphicsScene *scene;
    QBrush redBrush;//(QColor(255,0,0));
    QBrush greenBrush;//(QColor(0,255,0));

    QPen blackpen;//(QColor(0,0,0));
    QPen redpen;//(QColor(255,0,0));
    QList<QGraphicsEllipseItem*> nodes;
    QList<QGraphicsLineItem*> edges;
    void paintConcrete1();
    void paintNode(Process* pr, int x, int y, int r);
    void paintEdge(int x1, int y1, int x2, int y2, QPen &pen);
    Project* project;
    //QGraphicsEllipseItem
};

#endif // EDITPROJECTWIDJET_H
