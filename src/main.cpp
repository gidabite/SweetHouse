#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QTranslator>
#include "workermanager.h"
#include "serialization/serializer.h"
int main(int argc, char *argv[])
{
    //Q_INIT_RESOURCE(resource);
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load("sweethouse_ru", "/translations");
    a.installTranslator(&translator);
    MainWindow w;
    w.show();
    return a.exec();
}
