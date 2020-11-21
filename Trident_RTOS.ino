#include <TridentTD_EasyFreeRTOS32.h>

TridentOS   task1, task2;
void  task1_func(void*), timer_task(void*);


void task1_func(void*)  {  
  
  VOID SETUP() { 
    delay(300);
    Serial.println("task1 started");
  }
  VOID LOOP() {   
    delay(1);
  }
}

void timer_task(void*)  {
  int i = 0;
  
  VOID SETUP() {
    delay(300);
    Serial.println("timer_task started");
  }
  VOID LOOP() {
    Serial.printf("Timer event: %d\n\r", i++);
    delay(1000);
  }
}

void setup(){
  Serial.begin(115200); Serial.println();

  task1.start( task1_func );  
  task2.start( timer_task );	
}

void loop(){}
