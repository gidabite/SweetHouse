#ifndef EDITPROJECTWIDJET_H
#define EDITPROJECTWIDJET_H

#include <QWidget>
#include "project/project.h"

namespace Ui {
class EditProjectWidjet;
}

class EditProjectWidjet : public QWidget
{
    Q_OBJECT

public:
    explicit EditProjectWidjet(Project * project, QWidget *parent = 0);
    ~EditProjectWidjet();

    uint getId() const;
signals:
    void deleteProject(uint);
private:

    uint id;
    Ui::EditProjectWidjet *ui;
};

#endif // EDITPROJECTWIDJET_H
