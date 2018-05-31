#ifndef CREATEPROJTCTDIALOG_H
#define CREATEPROJTCTDIALOG_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class CreateProjtctDialog;
}

class CreateProjtctDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateProjtctDialog(QWidget *parent = 0);
    ~CreateProjtctDialog();
signals:

    saveProject(QString type, QString nameProject, QString address, QString lastName, QString name, QString middleName, QString pSeries, QString pNumber);
private slots:
    void on_pushButton_clicked();

private:
    bool check(QLineEdit *e);
    Ui::CreateProjtctDialog *ui;
};

#endif // CREATEPROJTCTDIALOG_H
