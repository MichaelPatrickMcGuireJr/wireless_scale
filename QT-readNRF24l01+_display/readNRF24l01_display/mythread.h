#ifndef MYTHREAD_H
#define MYTHREAD_H


#include <iostream>
#include <QThread>
#include <QMutex>





class mythread : public QThread
{
public:
    explicit mythread();

    void run();
    void stop_thread();
    QString get_val();


private:


    QMutex mutex;
    std::string receivedData;
    bool is_running;

};

#endif // MYTHREAD_H
