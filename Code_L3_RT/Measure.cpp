#include "Measure.hpp" 
#include "Gen_Tools.hpp"

/*
char a [10] = {'a','b','c','d','e','f','g','h','i','j'};
int S = 10;

void values_reading()
{
  Serial.println(a);
  for (int pos = 0; pos < (S-1); pos ++ )
  {
    a[pos] = a[pos+1]; 
  }  
}
*/



void values_reading()
{
  dato = analogRead(sensor);  
  for (int pos = 0; pos < (N-1); pos++)
  {
    sign[pos] = sign[pos+1];
  }
  sign[79] = dato;
  float temp = steinhart(dato);
  
  Serial.print(sign[79]);
  Serial.print(" , ");
  Serial.println(temp);
  
}



void freq_detection(){};
