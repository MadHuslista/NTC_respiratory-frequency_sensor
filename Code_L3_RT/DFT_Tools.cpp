#include "Gen_Tools.hpp"
#include "DFT_Tools.hpp"


float pi = 3.14159265358979323846;

float * dft(int *x)
{
  //int N = 80; 
  static float compl_amp [40] = {}; //[N/2]
  float re;
  float im;
  float phi;
  float amp;

  for( int k = 0; k < (N/2); k++) 
  {
    re = 0;
    im = 0;
    for( int n = 0; n < N; n++) 
    {
      phi = (2*pi*k*n)/N; 
      
      re = re + x[n]*cos(phi);
      im = im - x[n]*sin(phi);
    }
   //re = re/N;
   //im = im/N;
   amp = sqrt(re*re + im*im);
   
   compl_amp[k] = amp;
      
  }
  return compl_amp;  
}



float * avg(float *dft_sig)
{
  
  static float avg_sign [40] = {};  //N/2
  float avg_val = 0;
  for( int k = 1; k < (N/2)-1; k++) 
  {
    
    avg_val = (dft_sig[k-1]+dft_sig[k]+dft_sig[k+1])/3;
    avg_sign[k] = avg_val;  

    /*if (k > 7)
    {
    Serial.print(dft_sig[k]);
    Serial.print(" , ");
    Serial.println(avg_sign[k]);
    }*/
  }
  return avg_sign;
}
