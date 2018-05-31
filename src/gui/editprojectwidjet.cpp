#include "editprojectwidjet.h"
#include "ui_editprojectwidjet.h"

EditProjectWidjet::EditProjectWidjet(Project * project, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditProjectWidjet)
{
    ui->setupUi(this);
    this->id = project->getId();
}

EditProjectWidjet::~EditProjectWidjet()
{
    delete ui;
}

uint EditProjectWidjet::getId() const
{
    return id;
}
