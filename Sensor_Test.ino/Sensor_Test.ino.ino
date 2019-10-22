
int sensor = A0;

void setup() {
  pinMode(sensor,INPUT);
  Serial.begin(9600);

  analogReadResolution(12);   //Due

}

void loop() 
{
  values_reading();
}

float float_map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}




float volt_rest(int map_volt, int resist_val = 1000, char Duino = 'D')
{
  int resist;
  float Vs, volt;
  
  if (resist_val == 1000)       {resist = 989;}
  else if (resist_val == 10000) {resist = 10000;}

  if (Duino == 'D'){
    Vs = 3.26;                                          //Due
    volt = float_map(map_volt, 0, 4095, 0.2, Vs);}
  else if (Duino == 'U'){
    Vs = 4.47;                                        //Uno
    volt = float_map(map_volt, 0, 1023, 0.2, Vs);}


  float termist = (volt*resist - Vs*resist)/(-volt);
  return termist;
  
}

float steinhart(int map_volt, int resist_value = 1000)
{
  float termist = volt_rest(map_volt, resist_value);
  float ref, A, B, C, D;
  
  if (resist_value == 1000)
  {
    A = 3.354016E-03;
    B = 2.933908E-04;
    C = 3.494314E-06;
    D = -7.712690E-07;
    ref = 1000;
  }
  else if (resist_value == 10000)
  {
    A = 3.354016E-03;           
    B = 2.569850E-04;
    C = 2.620131E-06;
    D = 6.383091E-08;
    ref = 10000;
  }

  float res = termist/ref;

  float temp = 1/(A + B*log(res) + C*log(res)*log(res) + D*log(res)*log(res)*log(res)) - 273.15;
  return temp;
}

void values_reading()
{
  int dato = analogRead(sensor);  
  float temp = steinhart(dato, 1000);
  Serial.println(temp);
}
