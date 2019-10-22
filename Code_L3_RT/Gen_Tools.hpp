#ifndef Gen_Tools
#define Gen_Tools

#include <Arduino.h>




//Pin declaration
extern int led_wht;
extern int led_blu;
extern int led_grn;
extern int led_ylw;
extern int led_red;
extern int sensor;




//General Tool Functions
float steinhart(int map_volt);
float volt_rest(int map_volt);
float float_map(float x, float in_min, float in_max, float out_min, float out_max);




























#endif /* Gen_Tools */
