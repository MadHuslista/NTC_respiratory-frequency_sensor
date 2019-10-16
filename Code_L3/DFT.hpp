#ifndef DFT
#define DFT

#include <Arduino.h>

float * dft(int *x);
void detect_freq(int *x);
float * avg(float *dft_sig);


#endif /* DFT */
