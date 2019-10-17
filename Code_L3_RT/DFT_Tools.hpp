#ifndef DFT_Tools
#define DFT_Tools

#include <Arduino.h>

//DFT_Variables
extern float pi;

//DFT Tool Functions
float * dft(int *x);
float * avg(float *dft_sig);




#endif /* DFT_Tools */
