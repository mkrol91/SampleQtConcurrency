#ifndef MYJOB_H
#define MYJOB_H

#include <QObject>

class MyJob : public QObject
{
    Q_OBJECT
public:
    explicit MyJob(QObject *parent = 0);

signals:

public slots:
};

#endif // MYJOB_H