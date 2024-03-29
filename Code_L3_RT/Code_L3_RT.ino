#include "Activities.hpp"
#include "Gen_Tools.hpp"
#include "Process_Tools.hpp"
#include "Measure.hpp"
#include <Thread.h>
#include <ThreadController.h>

ThreadController controll = ThreadController();

Thread Thread_Read = Thread();
Thread Thread_FreqDetect = Thread(); 



void setup()
{
  pinMode(sensor,INPUT);
  pinMode(led_wht,OUTPUT);
  pinMode(led_blu,OUTPUT);
  pinMode(led_grn,OUTPUT);
  pinMode(led_ylw,OUTPUT);
  pinMode(led_red,OUTPUT);

  analogReadResolution(12);   //Due

  Thread_Read.onRun(values_reading);
  Thread_Read.setInterval(read_interval);
  
  Thread_FreqDetect.onRun(freq_detection);
  Thread_FreqDetect.setInterval(freq_detect_interval);

  controll.add(&Thread_Read);  
  controll.add(&Thread_FreqDetect);  

  
  Serial.begin(9600);
}


void loop()
{
  //P_1();
  //P_4();
  //P_5();
  P_6();
  controll.run();
}
