#include <Arduino_FreeRTOS.h>
#include <timers.h>

#define ONESECONDDELAY 1000/portTICK_PERIOD_MS
#define TWOSECONDDELAY 2000/portTICK_PERIOD_MS

void timer1_callback( TimerHandle_t xTimer ){
    Serial.println("Timer Done");
}

void timer2_callback( TimerHandle_t xTimer ){
    Serial.println("Timer 2 Done");
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //xTimerCreate(pcTimerName,xTimerPeriod, uxAutoReload,pvTimerID, pxCallbackFunction );
  TimerHandle_t timer1=xTimerCreate("1 second timer", ONESECONDDELAY, pdTRUE, 0, timer1_callback);
  TimerHandle_t timer2=xTimerCreate("2 second timer", TWOSECONDDELAY, pdTRUE, 0, timer2_callback);
  if (timer1 == NULL || timer2 == NULL) {
    Serial.println("A timer can not be created");
  } else {
    // Start timer
    if ((xTimerStart(timer1, 0) == pdPASS) && (xTimerStart(timer2, 0) == pdPASS )) { // Start the scheduler
      vTaskStartScheduler(); //start scheduler should start the timers
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}






