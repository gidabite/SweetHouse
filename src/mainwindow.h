#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "workermanager.h"
#include <QListWidget>
#include "gui/createworkerdialog.h"

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

private:
    void addItemToListWidget(QListWidget *lw, QWidget *item);
    WorkerManager *wm;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
