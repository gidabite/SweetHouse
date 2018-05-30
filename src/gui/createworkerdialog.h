#ifndef CREATEWORKERDIALOG_H
#define CREATEWORKERDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "worker/specialization.h"
#include "ui_createworker.h"

class CreateWorkerDialog : public QDialog
{
     Q_OBJECT
public:
    CreateWorkerDialog(QWidget *parent = 0);
    ~CreateWorkerDialog();
private:
    bool check(QLineEdit *e);
    bool checkSpecialization();
    Ui::Dialog *ui;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void on_pushButton_clicked();
signals:
    saveWorker(QString fio,QString pSeries, QString pNumber,  QList<Specialization*> specs);
};

#endif // CREATEWORKERDIALOG_H
