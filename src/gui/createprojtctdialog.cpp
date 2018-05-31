#include "createprojtctdialog.h"
#include "ui_createprojtctdialog.h"

CreateProjtctDialog::CreateProjtctDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateProjtctDialog)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Wooden House");
}

CreateProjtctDialog::~CreateProjtctDialog()
{
    delete ui;
}

bool CreateProjtctDialog::check(QLineEdit *e)
{
    bool p = true;
    if (e->text() == ""){
        p = false;
        e->setStyleSheet("border: 1px solid red");
    } else{
        e->setStyleSheet("border: 1px solid black");
    }
    return p;
}

void CreateProjtctDialog::on_pushButton_clicked()
{
    emit saveProject(ui->comboBox->currentText(), ui->lineProjectName->text(), ui->lineAddress->text(),ui->lineLastName->text(), ui->lineName->text(), ui->lineMiddleName->text(),ui->lineSeriesPassport->text(), ui->lineNumberPassport->text());
    emit close();
}
