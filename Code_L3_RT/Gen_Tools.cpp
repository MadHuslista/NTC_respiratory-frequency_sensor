#include "Gen_Tools.hpp"

//Sampling Values
int samp_freq = 2;    //(Hz)
int secs_record = 10; 
int N = int(samp_freq*secs_record);          //Cambiar manualmente en Gen_T{N}, Measure{sign[N-1]}, DFT_Tools{compl_amp[N/2], avg_sign[N/2] }
unsigned long read_interval = 1000/samp_freq;      //interval = 500ms, para una freq de sampleo de 2Hz considerando max freq de señal 0.5Hz
unsigned long freq_detect_interval = 300;


//Pin declaration 
int led_wht = 7;
int led_blu = 6;
int led_grn = 5;
int led_ylw = 4;
int led_red = 3; 
int sensor = A0;


//Reading_Variables
int dato; 
float sign [20];
int sign_pos = 0;


//General Tool Functions
float steinhart(int map_volt)
{
  float termist = volt_rest(map_volt);

  float A = 3.354016E-03;
  float B = 2.933908E-04;
  float C = 3.494314E-06;
  float D = -7.712690E-07;
  float ref = 1000;
  //float ref = 10000;

  float res = termist/ref;

  float temp = 1/(A + B*log(res) + C*log(res)*log(res) + D*log(res)*log(res)*log(res)) - 273.15;
  //Serial.println(temp);
  return temp;
}

float volt_rest(int map_volt)
{
  int resist = 989;
  //int resist = 10000;
  //float Vs = 4.47;                                        //Uno
  //float volt = float_map(map_volt, 0, 1023, 0.2, Vs);
  
  float Vs = 3.26;                                          //Due
  float volt = float_map(map_volt, 0, 4095, 0.2, Vs);
  
  float termist = (volt*resist - Vs*resist)/(-volt);
  return termist;
  
}

float float_map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
