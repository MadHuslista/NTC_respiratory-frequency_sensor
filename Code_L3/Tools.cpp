#include "Tools.hpp"


float samp_freq = 2; //(Hz)
float secs_record = 40; //
int const N = int(samp_freq*secs_record);    //Cambiar manualmente en sign, dft y Tools.hpp, y avg

int sign [80] = {};    //Calcular e ingresar el integer a mano. De otra manera falla por algo. 
int i = 0;
int dato;
int Flag = 0;
int h = 10; //En 10 y no en cero, para evitar graficar las frecuencias que parten en cero. 
float *dft_results;
float *avg_results;

float max_taquip = 30;  //max 30 resp/min = > max freq = 
float min_bradip = 10;

unsigned long current_time = millis();
unsigned long prev_time = 0;
unsigned long interval = 1000/samp_freq;  
unsigned long prev_interv = 0;

float pi = 3.14159265358979323846;


float maxim = 0;
float minim = 30;

int led_wht = 7;
int led_blu = 6;
int led_grn = 5;
int led_ylw = 4;
int led_red = 3; 

int sensor_read = A0;
int sensor_val;
int out_val;


float volt_rest(int map_volt)
{
  int resist = 989;
  //int resist = 10000;
  float Vs = 3.26;   //Due
  //float Vs = 4.47; //Uno
  float volt = float_map(map_volt, 0, 4095, 0.2, Vs);
  //Serial.println(volt);
  float termist = (volt*resist - Vs*resist)/(-volt);
  return termist;
  
}

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

float float_map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


/*float s [200] = { 0.00000000e+00,  2.44423518e+03, -1.08927949e+01,  2.63763342e+02,
       -1.22690899e+03,  6.40472342e+01, -8.90547174e+01, -1.61445904e+03,
        2.04861898e+03,  1.13037554e+03, -2.41254408e-01, -1.39605649e+03,
       -1.77070018e+03,  1.77347432e+03, -1.95504768e+02,  1.97224797e+02,
        1.08874586e+03, -2.62786095e+02, -1.22029583e+02, -2.56252917e+03,
        5.13246070e+02,  2.25555916e+03, -9.08899465e+01,  2.25005283e+02,
       -1.31958038e+03,  3.04968211e+02, -4.01306704e+02, -1.37342841e+03,
        2.25265417e+03,  8.76004159e+02, -6.46099875e+00, -1.65921943e+03,
       -1.42863126e+03,  1.84527836e+03, -4.36324598e+02,  4.62387348e+02,
        9.15721371e+02, -2.27443090e+02, -3.07095208e+02, -2.59920984e+03,
        1.00539959e+03,  2.01081145e+03, -1.20997092e+02,  1.44498046e+02,
       -1.35874627e+03,  5.09887699e+02, -7.23117903e+02, -1.05997301e+03,
        2.37721832e+03,  6.44681252e+02, -2.94272557e+01, -1.90479925e+03,
       -1.03584393e+03,  1.82935814e+03, -6.20345142e+02,  7.15209436e+02,
        7.20292331e+02, -1.66065733e+02, -5.39587070e+02, -2.54687814e+03,
        1.45650498e+03,  1.72646089e+03, -1.07702711e+02,  2.37412140e+01,
       -1.33963571e+03,  6.64973529e+02, -1.03530636e+03, -6.87533892e+02,
        2.42106065e+03,  4.45366366e+02, -7.87853814e+01, -2.11745107e+03,
       -6.08787434e+02,  1.72989777e+03, -7.38205903e+02,  9.40694930e+02,
        5.15841197e+02, -8.93430170e+01, -8.10992865e+02, -2.40250474e+03,
        1.84881267e+03,  1.42010525e+03, -6.03655743e+01, -1.32340495e+02,
       -1.26113925e+03,  7.59124058e+02, -1.31875262e+03, -2.72635874e+02,
        2.38719207e+03,  2.83752369e+02, -1.62011006e+02, -2.28255341e+03,
       -1.66054312e+02,  1.55551736e+03, -7.84725669e+02,  1.12599042e+03,
        3.15725437e+02, -9.54634643e+00, -1.10939723e+03, -2.16771663e+03,
        2.16771663e+03,  1.10939723e+03,  9.54634643e+00, -3.15725437e+02,
       -1.12599042e+03,  7.84725669e+02, -1.55551736e+03,  1.66054312e+02,
        2.28255341e+03,  1.62011006e+02, -2.83752369e+02, -2.38719207e+03,
        2.72635874e+02,  1.31875262e+03, -7.59124058e+02,  1.26113925e+03,
        1.32340495e+02,  6.03655743e+01, -1.42010525e+03, -1.84881267e+03,
        2.40250474e+03,  8.10992865e+02,  8.93430170e+01, -5.15841197e+02,
       -9.40694930e+02,  7.38205903e+02, -1.72989777e+03,  6.08787434e+02,
        2.11745107e+03,  7.87853814e+01, -4.45366366e+02, -2.42106065e+03,
        6.87533892e+02,  1.03530636e+03, -6.64973529e+02,  1.33963571e+03,
       -2.37412140e+01,  1.07702711e+02, -1.72646089e+03, -1.45650498e+03,
        2.54687814e+03,  5.39587070e+02,  1.66065733e+02, -7.20292331e+02,
       -7.15209436e+02,  6.20345142e+02, -1.82935814e+03,  1.03584393e+03,
        1.90479925e+03,  2.94272557e+01, -6.44681252e+02, -2.37721832e+03,
        1.05997301e+03,  7.23117903e+02, -5.09887699e+02,  1.35874627e+03,
       -1.44498046e+02,  1.20997092e+02, -2.01081145e+03, -1.00539959e+03,
        2.59920984e+03,  3.07095208e+02,  2.27443090e+02, -9.15721371e+02,
       -4.62387348e+02,  4.36324598e+02, -1.84527836e+03,  1.42863126e+03,
        1.65921943e+03,  6.46099875e+00, -8.76004159e+02, -2.25265417e+03,
        1.37342841e+03,  4.01306704e+02, -3.04968211e+02,  1.31958038e+03,
       -2.25005283e+02,  9.08899465e+01, -2.25555916e+03, -5.13246070e+02,
        2.56252917e+03,  1.22029583e+02,  2.62786095e+02, -1.08874586e+03,
       -1.97224797e+02,  1.95504768e+02, -1.77347432e+03,  1.77070018e+03,
        1.39605649e+03,  2.41254408e-01, -1.13037554e+03, -2.04861898e+03,
        1.61445904e+03,  8.90547174e+01, -6.40472342e+01,  1.22690899e+03,
       -2.63763342e+02,  1.08927949e+01, -2.44423518e+03, -4.00900376e-11 };*/
