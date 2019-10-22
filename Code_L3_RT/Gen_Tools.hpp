#ifndef Gen_Tools
#define Gen_Tools

#include <Arduino.h>

//Sampling Values
extern int samp_freq;                 //(Hz)
extern int secs_record;
extern int N;
extern unsigned long read_interval;     
extern unsigned long freq_detect_interval;


//Pin declaration
extern int led_wht;
extern int led_blu;
extern int led_grn;
extern int led_ylw;
extern int led_red;
extern int sensor;

//Reading_Variables
extern int dato; 
extern float sign [20] ;
extern int sign_pos ;



//General Tool Functions
float steinhart(int map_volt);
float volt_rest(int map_volt);
float float_map(float x, float in_min, float in_max, float out_min, float out_max);




























#endif /* Gen_Tools */
