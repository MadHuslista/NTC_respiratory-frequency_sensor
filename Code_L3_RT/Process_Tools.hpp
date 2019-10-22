#ifndef DFT_Tools
#define DFT_Tools

#include <Arduino.h>

//Sampling Values
extern int samp_freq;                 //(Hz)
extern int secs_record;
extern int N;
extern unsigned long read_interval;     
extern unsigned long freq_detect_interval;

//Reading_Variables
extern int dato; 
extern float sign [40] ;
extern int sign_pos ;


//DFT_Variables
extern float pi;
extern float DFT_results[20];
extern float AVG_results[40];

//DFT Tool Functions
float * dft(float *x, float *ampl);
float * avg(float *dft_sig, float *avg_sign);





#endif /* DFT_Tools */
