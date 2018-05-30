#include "editworkerwidget.h"

EditWorkerWidget::EditWorkerWidget(Worker* worker, QWidget *parent):
    QWidget(parent),
    ui(new Ui::EditWorkerWidget)
{
    ui->setupUi(this);
    ui->lineLastName->setText(worker->getLastName());
    ui->lineName->setText(worker->getName());
    ui->lineMiddleName->setText(worker->getMiddleName());
    ui->lineSeriesPassport->setText(worker->getPassportSeries());
    ui->lineNumberPassport->setText(worker->getPassportNumber());
    this->id = worker->getId();
    if (worker->isExistPossibleSpecialization(Builder::instance())) ui->checkBoxBuilder->setChecked(true);
    if (worker->isExistPossibleSpecialization(Electrician::instance())) ui->checkBoxElectician->setChecked(true);
    if (worker->isExistPossibleSpecialization(Foreman::instance())) ui->checkBoxForeman->setChecked(true);
    if (worker->isExistPossibleSpecialization(Manager::instance())) ui->checkBoxManager->setChecked(true);
    if (worker->isExistPossibleSpecialization(Plumber::instance())) ui->checkBoxPlumber->setChecked(true);
    if (worker->isExistPossibleSpecialization(Roofer::instance())) ui->checkBoxRoofer->setChecked(true);
    if (worker->isExistPossibleSpecialization(Surveyor::instance())) ui->checkBoxSurveyor->setChecked(true);
}

EditWorkerWidget::~EditWorkerWidget()
{
    delete ui;
}

bool EditWorkerWidget::check(QLineEdit *e){
    bool p = true;
    if (e->text() == ""){
        p = false;
        e->setStyleSheet("border: 1px solid red");
    } else{
        e->setStyleSheet("border: 1px solid black");
    }
    return p;
}

bool EditWorkerWidget::checkSpecialization()
{
    bool p = false;
    if(ui->checkBoxBuilder->isChecked() ||
       ui->checkBoxElectician->isChecked() ||
       ui->checkBoxForeman->isChecked() ||
       ui->checkBoxManager->isChecked() ||
       ui->checkBoxPlumber->isChecked() ||
       ui->checkBoxRoofer->isChecked() ||
       ui->checkBoxSurveyor->isChecked())
    {
        p = true;
        ui->groupBox->setStyleSheet("QGroupBox {border: 1px solid black}");
    } else
        ui->groupBox->setStyleSheet("QGroupBox {border: 1px solid red}");
    return p;
}

uint EditWorkerWidget::getId() const
{
    return id;
}

void EditWorkerWidget::closeEvent(QCloseEvent *event)
{
    delete this;
}


void EditWorkerWidget::on_pushButton_clicked()
{
    if (check(ui->lineLastName) & check(ui->lineName) & check(ui->lineMiddleName) & check(ui->lineSeriesPassport) & check(ui->lineNumberPassport) & checkSpecialization()){
        if (QMessageBox::Yes == QMessageBox::question(this, tr("Confirm Action"),
                                  tr("Are you sure?"),
                                  QMessageBox::Yes|QMessageBox::No))
            {
                QList<Specialization*> temp;
                if(ui->checkBoxBuilder->isChecked()) temp << Builder::instance();
                if(ui->checkBoxElectician->isChecked()) temp << Electrician::instance();
                if(ui->checkBoxForeman->isChecked()) temp << Foreman::instance();
                if(ui->checkBoxManager->isChecked()) temp << Manager::instance();
                if(ui->checkBoxPlumber->isChecked()) temp << Plumber::instance();
                if(ui->checkBoxRoofer->isChecked()) temp << Roofer::instance();
                if(ui->checkBoxSurveyor->isChecked()) temp << Surveyor::instance();
                emit updateWorker(id, ui->lineLastName->text(),ui->lineName->text(),ui->lineMiddleName->text(), ui->lineSeriesPassport->text(), ui->lineNumberPassport->text(), temp);
            }
    }
}

void EditWorkerWidget::on_pushButton_2_clicked()
{
    if (QMessageBox::Yes == QMessageBox::question(this, tr("Confirm Action"),
                              tr("Are you sure?"),
                              QMessageBox::Yes|QMessageBox::No))
    {
        emit deleteWorker(id);
    }
}
