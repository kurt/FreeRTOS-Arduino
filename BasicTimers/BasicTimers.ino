#include <Arduino_FreeRTOS.h>
#include <timers.h>

void timer1_callback( TimerHandle_t xTimer ){
    Serial.println("Timer Done");
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //xTimerCreate(pcTimerName,xTimerPeriod, uxAutoReload,pvTimerID, pxCallbackFunction );
  TimerHandle_t timer1=xTimerCreate("1 second timer", pdMS_TO_TICKS(1000), pdTRUE, 0, timer1_callback);
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




