#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "workermanager.h"
#include <QListWidget>
#include "gui/createworkerdialog.h"
#include "gui/editworkerwidget.h"
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
    void closeMyTab(int index);
    void clickWorker();
private:
    void fillListWorkers();
    void exportWorkers(QString path);
    void addItemToListWidget(QListWidget *lw, QWidget *item);
    WorkerManager *wm;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
