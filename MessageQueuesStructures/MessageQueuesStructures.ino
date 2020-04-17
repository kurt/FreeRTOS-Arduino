#include <Arduino_FreeRTOS.h>

struct sensor {
  int deviceID;
  int measurementType;
  float value;
};

QueueHandle_t queue;
int queueSize = 20;
 
void setup() {
 
  Serial.begin(112500);
 
  queue = xQueueCreate( queueSize, sizeof( sensor ) );
 
  if(queue == NULL){
    Serial.println("Error creating the queue");
  }
 
  xTaskCreate(
                    producerTask,     /* Task function. */
                    "Producer",       /* String with name of task. */
                    100,            /* Stack size in words. */
                    NULL,             /* Parameter passed as input of the task */
                    1,                /* Priority of the task. */
                    NULL);            /* Task handle. */
 
  xTaskCreate(
                    consumerTask,     /* Task function. */
                    "Consumer",       /* String with name of task. */
                    100,            /* Stack size in words. */
                    NULL,             /* Parameter passed as input of the task */
                    1,                /* Priority of the task. */
                    NULL);            /* Task handle. */
 
vTaskStartScheduler();
}
 
void loop() {
  Serial.println("Here");
  delay(1000);
}
 
void producerTask( void * parameter )
{
    struct sensor mySensor;
    mySensor.deviceID=10;
    mySensor.measurementType=1;
    for( int i = 0;i<10;i++ ){
      mySensor.value=i;
      xQueueSend(queue, &mySensor, portMAX_DELAY);
    }
 
    vTaskDelete( NULL );
 
}
 
void consumerTask( void * parameter)
{
    struct sensor element;
 
    for( int j = 0;j <10;j++ ){
 
        xQueueReceive(queue, &element, portMAX_DELAY);
        Serial.print(element.value);
        Serial.print("|");
    }
 
    vTaskDelete( NULL );
 
}
