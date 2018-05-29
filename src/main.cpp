#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QTranslator>
#include "workermanager.h"
#include "serialization/serializer.h"
int main(int argc, char *argv[])
{
    //Graph<Node> g;
    //Node first("First");
    //Node second("Second");
    //uint i1 = g.addNode(first);
    //uint i2 = g.addNode(second);
    //g.addEdge(i1, i2);
    WorkerManager *wm = WorkerManager::instance();
    (wm->addWorker("fio1","2222","222222"))->addPossibleSpecialization(Builder::instance());
    (wm->addWorker("fio2","3333","333333"))->addPossibleSpecialization(Builder::instance());

    QApplication a(argc, argv);
    QTranslator translator;
    translator.load("sweethouse_ru", "/translations");
    a.installTranslator(&translator);
    MainWindow w;
    w.show();

    return a.exec();
}
