#include "myjob.h"

MyJob::MyJob(QObject *parent) : QObject(parent)
{
    mStop = false;
}

void MyJob::start(QString name)
{
    mStop = false;
    for(int i= 0; i<99999; i++){
        if(mStop) return;
        qDebug() << "From thread: " << i;
        emit on_number(name, i);
        QThread::currentThread()->msleep(100);
    }
}

void MyJob::stop()
{
    mStop = true;
}

MyJob::~MyJob(){

}
