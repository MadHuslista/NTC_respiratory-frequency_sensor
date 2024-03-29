#include "Gen_Tools.hpp"
#include "Process_Tools.hpp"

//Sampling Values
int samp_freq                       = 2;    //(Hz)
int secs_record                     = 20; 
int N                               = int(samp_freq*secs_record);          //Cambiar manualmente en Gen_T{N}, Measure{sign[N-1]}, Process_Tools{compl_amp[N/2], avg_sign[N/2] }
unsigned long read_interval         = 1000/samp_freq;      //interval = 500ms, para una freq de sampleo de 2Hz considerando max freq de señal 0.5Hz
unsigned long freq_detect_interval  = 150;


//Reading_Variables
int dato; 
float sign [40];
int sign_pos = 0;

//DFT_Variables
float pi              = 3.14159265358979323846;
float DFT_results[20] = {};
float AVG_results[40] = {};


//DFT Tool Functions
float * dft(float *x, float *ampl)
{
  
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
   re = re/N;
   im = im/N;
   amp = sqrt(re*re + im*im);
   
   ampl[k] = amp;
      
  }
  
  return ampl;  
  
}



float * avg(float *sig, float *avg_sign)
{
  float avg_val = 0;
  for( int k = 1; k < (N-1); k++) 
  {
    
    avg_val = (sig[k-1]+sig[k]+sig[k+1])/3;
    avg_sign[k] = avg_val;  
  
  }
  avg_sign[0] = sig[0];
  avg_sign[39] = sig[39];
  return avg_sign;
}
