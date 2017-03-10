#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    emit on_stop();
    delete ui;
}


void Dialog::on_startButton_clicked()
{
    connect(&myJob, &MyJob::on_number, this, &Dialog::newNumber);
    connect(this, &Dialog::on_stop, &myJob, &MyJob::stop);

    QFuture<void> test = QtConcurrent::run(&this->myJob,&MyJob::start,QString("kitten"));
}

void Dialog::on_stopButton_clicked()
{
    emit on_stop();
}

void Dialog::newNumber(QString name, int number)
{
    qDebug() << "From dialog: " << name << " " << number;
    ui->lineEdit->setText(name + " " + QString::number(number));
}
