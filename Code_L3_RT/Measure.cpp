#include "Measure.hpp" 
#include "Gen_Tools.hpp"
#include "Process_Tools.hpp"




void values_reading()
{
  dato = analogRead(sensor);  
  float temp = steinhart(dato);
    
  for (int pos = 0; pos < (N-1); pos++)
  {
    sign[pos] = sign[pos+1];
  }
  sign[39] = temp;
}


void freq_detection()
{

  unsigned long tm = millis();
  float *pAVG_results = avg(sign, AVG_results);
  float *pDFT_results = dft(pAVG_results, DFT_results);

  //for (int p = 0; p < N; p ++)
  //{
  //  Serial.print(sign[p]);
  //  Serial.print(',');
  //  Serial.println(pAVG_results[p]);
  //}

  float actual_amp; 
  float actual_freq;

  float max_amp = 0;
  float interp_k = 0; 
  
  float bin_freq = 0; 
  float intr_freq = 0;
  
  for (int k = 0; k < (N/2); k++)
  {
    actual_amp = pDFT_results[k];
    actual_freq = float_map(k,0, N, 0, samp_freq); // or = float(k)/float(secs_record)
    
      

    if ((actual_amp > max_amp) && (actual_freq > 0.15))
    {
      max_amp = actual_amp;
      interp_k = float(k) + log(pDFT_results[k+1]/pDFT_results[k-1])/(2*log((pDFT_results[k]*pDFT_results[k])/(pDFT_results[k+1]*pDFT_results[k-1])));

      bin_freq = actual_freq;
      intr_freq = float_map(interp_k,0, N, 0, samp_freq);
      
      
    }

  }

  /*Serial.print("Frecuencia Respiratoria b: ");
  Serial.print(bin_freq);
  Serial.print("    Respiraciones por Minuto b: ");
  Serial.println(bin_freq*60, 3);
  
  Serial.print("Frecuencia Respiratoria i: ");
  Serial.print(intr_freq);
  Serial.print("    Respiraciones por Minuto i: ");
  Serial.println(intr_freq*60, 3);
  
  
  
  Serial.println(millis() - tm);
  Serial.println("      ");
  Serial.println("      ");
*/

  Serial.print(bin_freq*60, 3);
  Serial.print(',');
  Serial.println(intr_freq*60, 3);
  
  
}
