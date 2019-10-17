#ifndef DFT_Tools
#define DFT_Tools

#include <Arduino.h>

//DFT_Variables
extern float pi;
extern float DFT_signal_amps[100];
extern float sig2_ampl[100];
extern float windowed_sign[200];

//DFT Tool Functions
float * dft(float *x, float *ampl);
float * avg(float *dft_sig);
float * window(float *wr, float *wbhn); 





#endif /* DFT_Tools */
