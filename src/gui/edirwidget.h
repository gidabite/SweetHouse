#ifndef EDIRWIDGET_H
#define EDIRWIDGET_H

#include <QWidget>

namespace Ui {
class EdirWidget;
}

class EdirWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EdirWidget(bool type, QWidget *parent = 0);
    ~EdirWidget();

    uint getId() const;

    bool getType() const;

protected:
    uint id;
    bool type = false;
    Ui::EdirWidget *ui;
};

#endif // EDIRWIDGET_H
