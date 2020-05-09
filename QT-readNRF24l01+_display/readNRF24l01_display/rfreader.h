#ifndef RFREADER_H
#define RFREADER_H


#include <QObject>
#include <QDebug>
#include <QPoint>

#include "mythread.h"


class rfreader : public QObject
{
    Q_OBJECT
public:
    explicit rfreader(QObject *parent = nullptr);

    Q_INVOKABLE double get_double();
    Q_INVOKABLE QString get_qstring();
    Q_INVOKABLE void startThread();
    Q_INVOKABLE void stopThread();
    //Q_INVOKABLE void test();
    Q_INVOKABLE void read_sensor();

    mythread mthread;
    double sensor_val_double;
    QString sensor_val_qstring;


signals:

public slots:

};

#endif // RFREADER_H
