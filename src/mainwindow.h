#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "workermanager.h"
#include "projectmanager.h"
#include <QListWidget>
#include "gui/createworkerdialog.h"
#include "gui/createprojtctdialog.h"
#include "gui/editworkerwidget.h"
#include "gui/editprojectwidjet.h"
#include "gui/button.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void createNewWorker();
    void createNewProject();
    void saveWorker(QString lName,QString name, QString mName, QString pSeries, QString pNumber,  QList<Specialization*> specs);
    void updateWorker(uint id, QString lName,QString name, QString mName, QString pSeries, QString pNumber,  QList<Specialization*> specs);
    void deleteWorker(uint id);
    void saveProject(QString type, QString nameProject, QString address, QString lastName, QString name, QString middleName, QString pSeries, QString pNumber);
    void updateProject(uint id, QString type, QString nameProject, QString address, QString lastName, QString name, QString middleName, QString pSeries, QString pNumber);
    void deleteProject(uint id);
    void closeMyTab(int index);
    void clickWorker();
    void clickProject();
private:
    void fillListWorkers();
    void fillListProjects();
    void exportWorkers(QString path);
    void exportProjects(QString path);
    void addItemToListWidget(QListWidget *lw, QWidget *item);
    WorkerManager *wm;
    ProjectManager *pm;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
