#include "mythread.h"

#include <iostream>
//#include "../RF24/nRF24L01.h"
#include "./RF24.h"
#include <unistd.h>

using namespace std;

uint8_t pipeNumber;
uint8_t payloadSize;


#define PIN_CE  17
#define PIN_CSN 0

RF24 radio(17, 0);



mythread::mythread()
{
    radio.begin();
    radio.setChannel(5);
    radio.setPALevel(RF24_PA_MIN);
    radio.setDataRate(RF24_250KBPS);
    radio.enableDynamicPayloads();

    radio.openReadingPipe(0, 0x7878787878LL);

    radio.startListening();

    is_running = false;

}


void mythread::run()
{
    is_running = true;
    while(is_running)
    {
        if (radio.available(&pipeNumber))
        {

            payloadSize = radio.getDynamicPayloadSize();
            char payload[payloadSize];

            radio.read(&payload, sizeof(payload));

            mutex.lock();
            receivedData = "";
            for (uint8_t i = 0; i < payloadSize; i++)
            {
                receivedData += payload[i];
            }
            mutex.unlock();

            usleep(100000);
        }
        else
        {
            usleep(100000);
        }
    }
}


void mythread::stop_thread()
{
    is_running=false;
}


QString mythread::get_val()
{
    QString temp = "";

    if(is_running)
    {
        mutex.lock();
        temp = QString::fromStdString( receivedData );
        mutex.unlock();
    }
    else
    {
        temp = "-1";
    }
    return temp;
}


