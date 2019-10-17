
#include "Activities.hpp"
#include "Tools.hpp"
#include "DFT.hpp"


/*
  Para controlar la precisión del cálculo: 
  
  - El delta de freq entre los cuales 'decide' el dft está dado por frq_samp/N (porque después toma la máx freq medible -freq_samp/2, por Nyquist- y sobre ella divide
    las posibles freq desde 0 hsata freq_samp/2 uncantidad igual a N/2 veces. 

  - Aumentar el N se puede hacer aumentando la freq_samp o aumentando los sec_record. 
      - Aumentar la freq_samp, disminuye el delta de freq entre los que mira el dft, y permite leer freq más altas. 
      - Aumentar los sec_record, aumenta el delta de freq entre los que mira, sin aumentar el máximo ed freq.  

  - Entonces para controlar la precisión de la medición de la freq, aumentar los sec record (por consiguiente el N) y mantener la freq_samp en 2Hz. 
  - Los límites considerados plausibles son: 
              - Máxima Taquipnea de 30 resp/min
              - Mínima Bradipnea de 10 resp/min

*/
 
void setup() {
  pinMode(sensor_read,INPUT);

  pinMode(led_wht,OUTPUT);
  pinMode(led_blu,OUTPUT);
  pinMode(led_grn,OUTPUT);
  pinMode(led_ylw,OUTPUT);
  pinMode(led_red,OUTPUT);

  
  Serial.begin(9600);
 
}


void loop() {

  //P_1();
  //P_4();
  //P_5();
  P_6();
  //P_7();
  



}
