#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wm = WorkerManager::instance();
    pm = ProjectManager::instance();
    connect(ui->tabsContent,SIGNAL(tabCloseRequested(int)), this, SLOT(closeMyTab(int)));
    ui->tabsContent->removeTab(0);
    ui->tabsContent->removeTab(0);
    ui->tabsContent->removeTab(0);
    //Fill the listWorkrers
    fillListWorkers();

    //Fill the listWorkrers
    fillListProjects();
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createNewWorker()
{
    CreateWorkerDialog *cwd = new CreateWorkerDialog();
    QObject::connect(cwd, SIGNAL(saveWorker(QString, QString, QString, QString, QString, QList<Specialization*>)), this, SLOT(saveWorker(QString, QString, QString, QString, QString, QList<Specialization*>)));
    cwd->setModal(true);
    cwd->show();
}

void MainWindow::createNewProject()
{
    CreateProjtctDialog *cpd = new CreateProjtctDialog();
    QObject::connect(cpd, SIGNAL(saveProject(QString , QString , QString , QString , QString , QString , QString , QString )), this, SLOT(saveProject(QString , QString , QString , QString , QString , QString , QString , QString )));
    cpd->setModal(true);
    cpd->show();
}

void MainWindow::saveWorker(QString lName,QString name, QString mName,  QString pSeries, QString pNumber, QList<Specialization *> specs)
{
    wm->addWorker(lName, name, mName,pSeries,pNumber,specs);
    exportWorkers("workers.json");
    fillListWorkers();
}

void MainWindow::updateWorker(uint id, QString lName, QString name, QString mName, QString pSeries, QString pNumber, QList<Specialization *> specs)
{
    Worker* worker = wm->getWorkerById(id);
    worker->setLastName(lName);
    worker->setName(name);
    worker->setMiddleName(mName);
    worker->setPassportNumber(pNumber);
    worker->setPassportSeries(pSeries);
    worker->setMaskPossibleSpecs(specs);
    exportWorkers("workers.json");
    fillListWorkers();
}

void MainWindow::saveProject(QString type, QString nameProject, QString address, QString lastName, QString name, QString middleName, QString pSeries, QString pNumber)
{
    if (type == "Wooden House")
        pm->addConcreteProject1(nameProject,address,lastName,name,middleName,pSeries, pNumber);
    exportProjects("projects.json");
    fillListProjects();
}

void MainWindow::updateProject(uint id, QString type, QString nameProject, QString address, QString lastName, QString name, QString middleName, QString pSeries, QString pNumber)
{

}

void MainWindow::deleteProject(uint id)
{
    pm->deleteProject(id);
    (dynamic_cast<Button*>(ui->listProjects->itemWidget(ui->listProjects->item(id + 1)))->setIsShow(false));
    ui->tabsContent->removeTab(ui->tabsContent->indexOf((EditProjectWidjet*)sender()));
    exportWorkers("project.json");
    fillListWorkers();
}

void MainWindow::deleteWorker(uint id)
{
    wm->deleteWorker(id);
    (dynamic_cast<Button*>(ui->listWorkers->itemWidget(ui->listWorkers->item(id + 1)))->setIsShow(false));
    ui->tabsContent->removeTab(ui->tabsContent->indexOf((EditWorkerWidget*)sender()));
    exportWorkers("workers.json");
    fillListWorkers();
}

void MainWindow::closeMyTab(int index)
{
    EdirWidget *w = dynamic_cast<EdirWidget*>(ui->tabsContent->widget(index));
    uint id = w->getId();
    if (!w->getType())
        (dynamic_cast<Button*>(ui->listWorkers->itemWidget(ui->listWorkers->item(id + 1)))->setIsShow(false));
    else
        (dynamic_cast<Button*>(ui->listProjects->itemWidget(ui->listProjects->item(id + 1)))->setIsShow(false));
    ui->tabsContent->removeTab(index);
}

void MainWindow::clickWorker(){
    Button * btn = (Button*)sender();
    if (!(btn->getIsShow())){
        btn->setIsShow(true);
        Worker* worker = wm->getWorkerById(btn->getId());
        EditWorkerWidget *newTab = new EditWorkerWidget(worker, ui->tabsContent);
        QObject::connect(newTab, SIGNAL(updateWorker(uint, QString, QString, QString, QString, QString, QList<Specialization*>)), this, SLOT(updateWorker(uint, QString, QString, QString, QString, QString, QList<Specialization*>)));
        QObject::connect(newTab, SIGNAL(deleteWorker(uint)), this, SLOT(deleteWorker(uint)));
        ui->tabsContent->addTab(newTab, worker->getLastName() + " " +  worker->getName()[0]+ ". " + worker->getMiddleName()[0] + ".");
        ui->tabsContent->setCurrentWidget(newTab);
    }
}

void MainWindow::clickProject()
{
    Button * btn = (Button*)sender();
    if (!(btn->getIsShow())){
        btn->setIsShow(true);
        Project* project = pm->getProjectById(btn->getId());
        EditProjectWidjet *newTab = new EditProjectWidjet(project, ui->tabsContent);
        QObject::connect(newTab, SIGNAL(updateProject(uint, QString type, QString nameProject, QString address, QString lastName, QString name, QString middleName, QString pSeries, QString pNumber)), this, SLOT(updateProject(uint, QString type, QString nameProject, QString address, QString lastName, QString name, QString middleName, QString pSeries, QString pNumber)));
        QObject::connect(newTab, SIGNAL(deleteProject(uint)), this, SLOT(deleteProject(uint)));
        ui->tabsContent->addTab(newTab, project->getNameProject());
        ui->tabsContent->setCurrentWidget(newTab);
    }
}

void MainWindow::fillListWorkers()
{
    ui->listWorkers->clear();
    QPushButton * addWorkerButton = new QPushButton();
    addWorkerButton->setMinimumHeight(41);
    addWorkerButton->setIcon(QIcon(":/images/images/add.png"));
    addWorkerButton->setIconSize(QSize(64,64));
    QObject :: connect(addWorkerButton, SIGNAL(clicked(bool)), SLOT(createNewWorker()));
    this->addItemToListWidget(ui->listWorkers, addWorkerButton);
    QList<Worker> workers = wm->getWorkers();
    for (QList<Worker>::const_iterator iter = workers.constBegin(); iter != workers.constEnd(); iter++){
        Button * addWorkerButton = new Button();
        addWorkerButton->setId(iter->getId());
        addWorkerButton->setMinimumHeight(41);
        addWorkerButton->setText(iter->getLastName() + " " +  iter->getName()[0]+ ". " + iter->getMiddleName()[0] + ".");
        addWorkerButton->setIconSize(QSize(64,64));
        connect(addWorkerButton, SIGNAL(clicked(bool)), SLOT(clickWorker()));
        this->addItemToListWidget(ui->listWorkers, addWorkerButton);
    }
}

void MainWindow::fillListProjects()
{
    ui->listProjects->clear();
    QPushButton * addProjectButton = new QPushButton();
    addProjectButton->setMinimumHeight(41);
    addProjectButton->setIcon(QIcon(":/images/images/add.png"));
    addProjectButton->setIconSize(QSize(64,64));
    QObject :: connect(addProjectButton, SIGNAL(clicked(bool)), SLOT(createNewProject()));
    this->addItemToListWidget(ui->listProjects, addProjectButton);
    QList<Project> projects = pm->getProjects();
    for (QList<Project>::const_iterator iter = projects.constBegin(); iter != projects.constEnd(); iter++){
        Button * addProjectButton = new Button();
        addProjectButton->setId(iter->getId());
        addProjectButton->setMinimumHeight(41);
        addProjectButton->setText(iter->getNameProject());
        addProjectButton->setIconSize(QSize(64,64));
        connect(addProjectButton, SIGNAL(clicked(bool)), SLOT(clickProject()));
        this->addItemToListWidget(ui->listProjects, addProjectButton);
    }
}

void MainWindow::exportWorkers(QString path)
{
    QFile out(path);
    if (out.open(QFile::WriteOnly)){
        out.write((Serializer<WorkerManager>::serialize(*wm)).toUtf8());
        out.close();
    }
}

void MainWindow::exportProjects(QString path)
{
    QFile out(path);
    if (out.open(QFile::WriteOnly)){
        out.write((Serializer<ProjectManager>::serialize(*pm)).toUtf8());
        out.close();
    }
}

void MainWindow::addItemToListWidget(QListWidget *lw, QWidget *item)
{
    QListWidgetItem *listWidgetItem = new QListWidgetItem(lw);
    listWidgetItem->setSizeHint(QSize(188, 41));
    lw->addItem(listWidgetItem);
    lw->setItemWidget(listWidgetItem, item);
}

