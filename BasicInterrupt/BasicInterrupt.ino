
/*
Plug in a wire from Pin 13 to Pin 2!!! This is how TASK 1 gets triggered
*/
#include <Arduino_FreeRTOS.h>

const int InterruptPin = 2;     // the number of the pushbutton pin
const int TriggerPin =  13;         // Trigger interrupt
TaskHandle_t xHandle1;
TaskHandle_t xHandle2;
void setup(){
	Serial.begin(9600);
        pinMode(InterruptPin, INPUT);
        pinMode(TriggerPin, OUTPUT);
	xTaskCreate(MyTask1,"Task1",100,NULL,1, &xHandle1);
        xTaskCreate(MyTask2,"Task2",100,NULL,2, &xHandle2);
	attachInterrupt(0,ExternalInterrupt,FALLING);//pin 2
	vTaskStartScheduler();
}


void loop(){
}

static void ExternalInterrupt(){
        vTaskResume( xHandle1 );
}

/* Task1 with priority 1 */
static void MyTask1(void* pvParameters)
{
  while(1)
  {
    Serial.println(F("Task1"));
    vTaskSuspend( xHandle1 );
    //vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

/* Task1 with priority 1 */
static void MyTask2(void* pvParameters)
{
  static int signal =0;
  const TickType_t xDelay = 100;
  while(1)
  {
    Serial.println(F("Task2"));
    digitalWrite(TriggerPin,HIGH);
     vTaskDelay(xDelay);
    digitalWrite(TriggerPin,LOW);
  }
}
