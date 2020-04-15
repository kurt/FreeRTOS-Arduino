#include <Arduino_FreeRTOS.h>
QueueHandle_t the_message_queue;
int queueSize=16; 

void setup() {
  Serial.begin(112500);
  the_message_queue=xQueueCreate(queueSize,sizeof(int));
  if (the_message_queue == NULL){
   Serial.println("Error creating queue"); 
  }

 //xTaskCreate(TaskFunctionName,"TaskHandleName",StackDepthInWords,PassedinParameter, TaskPriority, pxCreatedTask );
  xTaskCreate(Task1,"Task1Handle",100,NULL,1,NULL); //more important
  xTaskCreate(Task2,"Task2Handle",100,NULL,1,NULL); //less important
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("In the main loop");
  delay(100000);

}


void Task1(void * pvParameters){
  //Serial.println("In T1");
  for(int i=0;i<queueSize;i++){
   xQueueSend(the_message_queue,&i,portMAX_DELAY);
   }
  vTaskDelete(NULL);//delete this task
}//end of Task1


void Task2(void * pvParameters){
  int element;
  //Serial.println("In T2");
  for(int i=0;i<queueSize;i++){
    xQueueReceive(the_message_queue, &element,portMAX_DELAY);
    Serial.print(element);
    Serial.print("|");
  }
  vTaskDelete; //delete this task 
}//end of Task1
