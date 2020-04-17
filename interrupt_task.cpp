
#include <Arduino_FreeRTOS.h>

TaskHandle_t xHandle1;

void setup(){
	Serial.begin(9600);
	xTaskCreat(MyTask1,"Task1",100,NULL,1, &xHandle1);
	attachInterrupt(digitalPinToInterrupt(2),ExternalInterrupt,FALLING);
	vTaskStartScheduler();
}


void loop(){
}

static void ExternalInterrupt(){
	xTaskResumeFromISR(xHandle1);
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