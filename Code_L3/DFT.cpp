
#include "DFT.hpp"
#include "Tools.hpp"

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

void detect_freq(int *x)
{
  float *dft_r = dft(x);
  float *avg_r = avg(dft_r);
  float max_amp = 0;
  float freq = 0;
  float freq_s = 0;
  for( int k = 7; k < (N/2); k++) 
  {
    //Serial.println(dft_r[k]);
    
    freq_s = float_map(k,0, N, 0, samp_freq);

    
    Serial.print(avg_r[k]);
    Serial.print("  ");
    Serial.println(freq_s,3);
    
    //if (dft_r[k] > max_amp)
    if (avg_r[k] > max_amp)
    {
      //max_amp = dft_r[k];
      max_amp = avg_r[k];
      freq = float_map(k,0, N, 0, samp_freq);
      
    }
  }
  
  Serial.print("Respiraciones por Minuto: ");
  Serial.println(freq*60, 3);
  Serial.print("Frecuencia Resp: ");
  Serial.print(freq,3);
  Serial.println(" [Hz]");
  Serial.print(1/freq,3);
  Serial.println(" [s]");
  
}

float * avg(float *dft_sig)
{
  
  static float list [40] = {};
  float avg_val = 0;
  for( int k = 1; k < (N/2)-1; k++) 
  {
    //Serial.print(dft_sig[k]);
    //Serial.print("   ");
    //Serial.print(dft_sig[k+1]);
    //Serial.print("   ");
    
    avg_val = (dft_sig[k-1]+dft_sig[k]+dft_sig[k+1])/3;
    //Serial.print(avg_val);
    list[k] = avg_val;  
    //Serial.print("   ");  
    //Serial.println(avg_val);
  }
  return list;
}
