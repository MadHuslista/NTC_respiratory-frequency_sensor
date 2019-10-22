#ifndef DFT_Tools
#define DFT_Tools

#include <Arduino.h>

//DFT_Variables
extern float pi;
extern float DFT_signal_amps[10];
extern float sig2_ampl[10];
extern float windowed_sign[20];

//DFT Tool Functions
float * dft(float *x, float *ampl);
float * avg(float *dft_sig);
float * window(float *wr, float *wbhn); 





#endif /* DFT_Tools */
