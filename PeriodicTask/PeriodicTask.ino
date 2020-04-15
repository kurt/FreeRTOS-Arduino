#include <Arduino_FreeRTOS.h>
#include <timers.h>
TaskHandle_t xHandle1;

void timer1_callback( TimerHandle_t xTimer ){
    Serial.println("Timer Done");
    vTaskResume( xHandle1 );
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //xTimerCreate(pcTimerName,xTimerPeriod, uxAutoReload,pvTimerID, pxCallbackFunction );
  TimerHandle_t timer1=xTimerCreate("1 second timer", pdMS_TO_TICKS(1000), pdTRUE, 0, timer1_callback);
  xTaskCreate(MyTask1, "Task1", 100, NULL, 1, &xHandle1);
  if (timer1 == NULL) {
    Serial.println("Timer can not be created");
  } else {
    // Start timer
    if (xTimerStart(timer1, 0) == pdPASS) { // Start the scheduler
      vTaskStartScheduler(); //start scheduler should start the timers
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

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


