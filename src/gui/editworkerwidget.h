#ifndef EDITWORKERWIDGET_H
#define EDITWORKERWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "worker/worker.h"
#include "ui_editworker.h"


class EditWorkerWidget: public QWidget
{
    Q_OBJECT
public:
   EditWorkerWidget(Worker* worker, QWidget *parent = 0 );
   ~EditWorkerWidget();
   uint getId() const;

private:
   bool check(QLineEdit *e);
   bool checkSpecialization();
   Ui::EditWorkerWidget *ui;
   uint id;
   // QWidget interface
protected:
   void closeEvent(QCloseEvent *event);
private slots:
   void on_pushButton_clicked();
   void on_pushButton_2_clicked();

signals:
   updateWorker(uint id, QString lName,QString name, QString mName, QString pSeries, QString pNumber,  QList<Specialization*> specs);
   deleteWorker(uint id);
};

#endif // EDITWORKERWIDGET_H
