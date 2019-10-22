#ifndef Tools
#define Tools

#include <Arduino.h>


extern float samp_freq;
extern float secs_record;
extern int const N;

extern float max_taquip;
extern float min_bradip;

extern int sign [80] ;
extern int i;
extern int dato;
extern int Flag;
extern int h;
extern float *dft_results;
extern float *avg_results;

extern unsigned long current_time;
extern unsigned long prev_time;
extern unsigned long interval;
extern unsigned long prev_interv;
extern float pi;



extern float maxim;
extern float minim;

extern int led_wht;
extern int led_blu;
extern int led_grn;
extern int led_ylw;
extern int led_red;

extern int sensor_read;
extern int sensor_val;
extern int out_val;

float steinhart(int map_volt);
float volt_rest(int map_volt);
float float_map(float x, float in_min, float in_max, float out_min, float out_max);


//extern float s [200];


#endif /* Tools */
