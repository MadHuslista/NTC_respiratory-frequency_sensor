#include "Measure.hpp" 
#include "Gen_Tools.hpp"
#include "DFT_Tools.hpp"

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
  for (int pos = 0; pos < (N-1); pos++)
  {
    sign[pos] = sign[pos+1];
  }
  sign[19] = dato;
  float temp = steinhart(dato);

  /*Serial.print(sign[0]);
  Serial.print(" ... ");
  Serial.print(sign[67]);
  Serial.print(" ");
  Serial.print(sign[68]);
  Serial.print(" ");
  Serial.print(sign[69]);
  Serial.print(" ");
  Serial.print(sign[70]);
  Serial.print(" ");
  Serial.print(sign[71]);
  Serial.print(" ");
  Serial.print(sign[72]);
  Serial.print(" ");
  Serial.print(sign[73]);
  Serial.print(" ");
  Serial.print(sign[74]);
  Serial.print(" ");
  Serial.print(sign[75]);
  Serial.print(" ");
  Serial.print(sign[76]);
  Serial.print(" ");
  Serial.print(sign[77]);
  Serial.print(" ");
  Serial.print(sign[78]);
  Serial.print(" ");
  Serial.print(sign[79]);
  Serial.print(" , ");
  Serial.println(temp);*/
}


void freq_detection()
{
  unsigned long tm = millis();
  float * wins_pnt = window(sign, windowed_sign);
  float *DFT_results = dft(sign, DFT_signal_amps);
  //float *AVG_results = avg(DFT_results);
  float max_amp = 0;
  float freq = 0;
  float freq_s = 0;
  for (int k = 0; k < (N/2); k++)    
  {
    freq_s = float_map(k,0, N, 0, samp_freq);
    Serial.print(DFT_results[k]);
    Serial.print("  ");
    Serial.println(freq_s,3);
    
    //if (dft_r[k] > max_amp)
    if ((DFT_results[k] > max_amp)&&(freq_s > 0.15))
    {
      //max_amp = dft_r[k];
      max_amp = DFT_results[k];
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
  Serial.println((millis()-tm));
}
