#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wm = WorkerManager::instance();

    //Fill the listWorkrers
    QPushButton * addWorkerButton = new QPushButton();
    addWorkerButton->setMinimumHeight(41);
    addWorkerButton->setIcon(QIcon(":/images/images/add.png"));
    addWorkerButton->setIconSize(QSize(64,64));
    QObject :: connect(addWorkerButton, SIGNAL(clicked(bool)), SLOT(createNewWorker()));
    this->addItemToListWidget(ui->listWorkers, addWorkerButton);

    //Fill the listWorkrers
    QPushButton * addProjectButton = new QPushButton();
    addProjectButton->setMinimumHeight(41);
    addProjectButton->setIcon(QIcon(":/images/images/add.png"));
    addProjectButton->setIconSize(QSize(64,64));
    QObject :: connect(addProjectButton, SIGNAL(clicked(bool)), SLOT(createNewProject()));
    this->addItemToListWidget(ui->listProjects, addProjectButton);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createNewWorker()
{
    CreateWorkerDialog *cwd = new CreateWorkerDialog();
    cwd->setModal(true);
    cwd->show();
}

void MainWindow::createNewProject()
{

}

void MainWindow::addItemToListWidget(QListWidget *lw, QWidget *item)
{
    QListWidgetItem *listWidgetItem = new QListWidgetItem(lw);
    lw->addItem(listWidgetItem);
    lw->setItemWidget(listWidgetItem, item);
}

