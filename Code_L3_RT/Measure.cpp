#include "Measure.hpp" 
#include "Gen_Tools.hpp"
#include "Process_Tools.hpp"

/*void foo()
{
  float * wins_pnt = window(sign, win_sig );
  float * win_result = dft(wins_pnt, sig_ampl);
  float * dft_result = dft(sign, sig2_ampl);
  for (int i = 0; i < N; i++)
  {
    Serial.print(sign[i]);
    Serial.print(" , ");
    Serial.print(win_sig[i]);
    Serial.print(" , ");
    Serial.print(dft_result[i]);
    Serial.print(" , ");
    Serial.println(win_result[i]);
  }
}*/



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
    
    //Serial.print(actual_amp);
    //Serial.print("   ,    ");
    //Serial.print(actual_freq);    

    if ((actual_amp > max_amp) && (actual_freq > 0.15))
    {
      max_amp = actual_amp;
      interp_k = float(k) + log(pDFT_results[k+1]/pDFT_results[k-1])/(2*log((pDFT_results[k]*pDFT_results[k])/(pDFT_results[k+1]*pDFT_results[k-1])));

      bin_freq = actual_freq;
      intr_freq = float_map(interp_k,0, N, 0, samp_freq);
      
      //Serial.print("   ,    ");
      //Serial.print(bin_freq);
      //Serial.print("   ,    ");
      //Serial.print(intr_freq);
    }
    //Serial.println();
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
  Serial.println(millis() - tm);
  
}
  /*
  
  float max_amp = 0;
  float freq_bin = 0;
  float freq_int = 0;
  float freq_pos = 0;
  float k_interpolation = 0;
  
  for (int k = 1; k < (N/2)-1; k++)
  {
    freq_pos = float_map(k,0, N, 0, samp_freq);
    Serial.print(DFT_results[k]);
    Serial.print("  ");
    Serial.println(freq_pos,3);
  
    if ((DFT_results[k] > max_amp)&&(freq_pos > 0.15))   
      {                                                
        max_amp = DFT_results[k];
        
        k_interpolation = k + log(DFT_results[k+1]/DFT_results[k-1])/(2*log((DFT_results[k]*DFT_results[k])/(DFT_results[k+1]*DFT_results[k-1])));
              
        
        freq_bin = float_map(k,0, N, 0, samp_freq);   // [!!!] Revisar tiempo que demora en hacer esto. Si toma mucho tiempo se puede resumir. freq = float_map(k) = k* (samp_freq - 0)/(N- 0) = k / (samp_time * N) = k / sec_record. 
        freq_int = float_map(k_interpolation, 0, N, 0, samp_freq);   
      }
  }
  Serial.print("Amp:");
  Serial.println(k_interpolation);
  Serial.print("Respiraciones por Minuto: ");
  Serial.println(freq_int*60, 3);
  Serial.print("Frecuencia Resp: ");
  Serial.print(freq_int,3);
  Serial.println(" [Hz]");
  Serial.print(1/freq_int,3);
  Serial.println(" [s]");
  Serial.println((millis()-tm));
  
}*/
