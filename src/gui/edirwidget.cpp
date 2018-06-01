#include "edirwidget.h"
#include "ui_edirwidget.h"

EdirWidget::EdirWidget(bool type, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EdirWidget),
    type(type)
{
    ui->setupUi(this);
}

EdirWidget::~EdirWidget()
{
    delete ui;
}

uint EdirWidget::getId() const
{
    return id;
}

bool EdirWidget::getType() const
{
    return type;
}
