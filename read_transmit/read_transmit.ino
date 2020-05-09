#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include "HX711.h"
#include <RF24.h>
#include <string.h>

// define portCHAR
#define portCHAR    char

// define calibration factor and pins for scale module (HX711)
#define calibration_factor -7050.0
#define DOUT  3
#define CLK  2

// define pins for RF communication module (NRF24l01+)
#define PIN_CE 53
#define PIN_CSN 48



// define mutex 
SemaphoreHandle_t xSerialSemaphore;

// define two tasks for Blink & AnalogRead
void TaskGetWeight( void *pvParameters );
void TaskSendValue( void *pvParameters );

volatile char getWeight[10] = "";
volatile char toSend[10] = "NA";
volatile char go[2] = "20";


// Setup
void setup() {

  // Open serial monitor
  Serial.begin(9600);

  // Create Semaphore 
  if ( xSerialSemaphore == NULL )
  {
    xSerialSemaphore = xSemaphoreCreateMutex();
    if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) );
  }


  // setup tasks to run gather reading from scale and transmit wirelessly
  xTaskCreate(
    TaskGetWeight
    ,  (const portCHAR *) "GetWeight"
    ,  128  // Stack size
    ,  NULL
    ,  2  // priority
    ,  NULL );

  xTaskCreate(
    TaskSendValue
    ,  (const portCHAR *) "SendValue"
    ,  128
    ,  NULL
    ,  1
    ,  NULL );


}

void loop()
{
  // Empty. Things are done in Tasks.
}


//  Tasks

// Obtain weight measurements
void TaskGetWeight(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  float weight = 0;

  HX711 scale;
  
  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0


  

  for (;;) // A Task shall never return or exit.
  {

    weight = scale.get_units();  //scale.get_units() returns a float
    
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
    {

      String(weight, 2).toCharArray(getWeight, 10);    
      xSemaphoreGive( xSerialSemaphore );
    }

    
    vTaskDelay( 250 / portTICK_PERIOD_MS ); // wait for one second
  }
}


// transmit weight value wirelessly
void TaskSendValue(void *pvParameters)
{
  (void) pvParameters;

  uint8_t pipeNumber;
  uint8_t payloadSize;
  uint8_t packet_num;
  const uint64_t pipeNum = 0x7878787878LL;
  RF24 radio(PIN_CE, PIN_CSN);

  packet_num = 0;
  
  radio.begin();
  radio.setChannel(5);
  radio.setDataRate (RF24_250KBPS);
  radio.setPALevel(RF24_PA_MIN);
  radio.enableDynamicPayloads();
  radio.openWritingPipe(pipeNum);


  for (;;)
  {

    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
    {
      strlcpy((char*)toSend,(char*)getWeight,10);
      xSemaphoreGive( xSerialSemaphore );
    }

    
    
    //if (radio.write(&toSend, sizeof(toSend)))
    if (radio.write(&toSend, sizeof(toSend))) 
    {
      char *x = { toSend };
      Serial.print( "---" );
      Serial.print( x );
      Serial.print( "!!!\n" );
    }
    else 
    {
      Serial.println("Data not delivered");
    }

    
    vTaskDelay( 500 / portTICK_PERIOD_MS );  // one tick delay (15ms) in between reads for stability
  }
}
