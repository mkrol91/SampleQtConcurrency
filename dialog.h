#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include "myjob.h"
#include <QtConcurrent>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

signals:
    void on_stop();

private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

public slots:
    void newNumber(QString name, int number);

private:
    Ui::Dialog *ui;
    MyJob myJob;
};

#endif // DIALOG_H
