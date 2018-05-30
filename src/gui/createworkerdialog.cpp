#include "createworkerdialog.h"

CreateWorkerDialog::CreateWorkerDialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

CreateWorkerDialog::~CreateWorkerDialog()
{
    delete ui;
}

bool CreateWorkerDialog::check(QLineEdit *e){
    bool p = true;
    if (e->text() == ""){
        p = false;
        e->setStyleSheet("border: 1px solid red");
    } else{
        e->setStyleSheet("border: 1px solid black");
    }
    return p;
}

bool CreateWorkerDialog::checkSpecialization()
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

void CreateWorkerDialog::closeEvent(QCloseEvent *event)
{
    delete this;
}


void CreateWorkerDialog::on_pushButton_clicked()
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
                emit saveWorker(ui->lineLastName->text() + ui->lineName->text() + ui->lineMiddleName->text(), ui->lineSeriesPassport->text(), ui->lineNumberPassport->text(), temp);
                emit close();
            }
    }
}
