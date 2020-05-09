#include "rfreader.h"

#include <QDebug>

rfreader::rfreader(QObject *parent) : QObject(parent)
{
    //isRunning = false;
    sensor_val_double = -1;
    sensor_val_qstring = "-1";

}

double rfreader::get_double()
{
    return sensor_val_double;
}

QString rfreader::get_qstring()
{
    qDebug() << "val3 = " << sensor_val_qstring;
    return sensor_val_qstring;
}

void rfreader::startThread()
{

    //qDebug() << "here1 \n";
    mthread.start();
    //qDebug() << "here2 \n";

}

void rfreader::stopThread()
{

    //isRunning = false;
    mthread.stop_thread();

}

void rfreader::read_sensor()
{
    bool ok = false;

    QString temp = mthread.get_val();
    int decimal_point = temp.indexOf(".");
    if(decimal_point>=1)
    {
        temp = temp.left( decimal_point+3 );
    }
    qDebug() << "val1 = " << temp;


    double tempD = temp.toDouble(&ok);
    tempD = tempD*22;
    sensor_val_double = tempD*2;
    sensor_val_qstring = QString::number(tempD);
qDebug() << "val2 = " << sensor_val_qstring;

}
