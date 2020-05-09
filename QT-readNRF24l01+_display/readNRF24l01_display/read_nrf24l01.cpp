#include "read_nrf24l01.h"


#include <iostream>
//#include "../RF24/nRF24L01.h"
#include "./RF24.h"
#include <unistd.h>

using namespace std;

#define PIN_CE  17
#define PIN_CSN 0

uint8_t pipeNumber;
uint8_t payloadSize;

RF24 radio(PIN_CE, PIN_CSN);


read_NRF24l01::read_NRF24l01()
{

}


int read_NRF24l01::init_sensor()
{

    radio.begin();
    radio.setChannel(5);
    radio.setPALevel(RF24_PA_MIN);
    radio.setDataRate(RF24_250KBPS);
    radio.enableDynamicPayloads();

    radio.openReadingPipe(0, 0x7878787878LL);

    radio.startListening();

    return 0;
}


double read_NRF24l01::update_val()
{



    if (radio.available(&pipeNumber))
    {

          payloadSize = radio.getDynamicPayloadSize();
          char payload[payloadSize];
          string receivedData;
          radio.read(&payload, sizeof(payload));

          for (uint8_t i = 0; i < payloadSize; i++) {
              receivedData += payload[i];
          }

          usleep(100000);
    }
    else
    {
        usleep(100000);
    }




    return 0;
}
