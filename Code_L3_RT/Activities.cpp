
#include "Activities.hpp"
#include "Gen_Tools.hpp"
#include "Process_Tools.hpp"



void P_1()
{
  dato = analogRead(sensor);
  float temp = steinhart(dato);
  Serial.print(dato);
  Serial.print("   ");
  Serial.print(temp);
  Serial.println(" °C");
}

void P_4()
{
  dato = analogRead(sensor);
  float temp = steinhart(dato);
  int out_val = map(temp, 25, 34, 2, 7);
  Serial.print(temp);
  Serial.print("   ");
  Serial.println(out_val);


  if (out_val == 2)
  {
    digitalWrite(led_wht, LOW);
    digitalWrite(led_blu, LOW);
    digitalWrite(led_grn, LOW);
    digitalWrite(led_ylw, LOW);
    digitalWrite(led_red, LOW);
  }
  else if (out_val == 3)
  {
    digitalWrite(led_wht, HIGH);
    digitalWrite(led_blu, LOW);
    digitalWrite(led_grn, LOW);
    digitalWrite(led_ylw, LOW);
    digitalWrite(led_red, LOW);
  }
  else if (out_val == 4)
  {
    digitalWrite(led_wht, HIGH);
    digitalWrite(led_blu, HIGH);
    digitalWrite(led_grn, LOW);
    digitalWrite(led_ylw, LOW);
    digitalWrite(led_red, LOW);
  }
  else if (out_val == 5)
  {
    digitalWrite(led_wht, HIGH);
    digitalWrite(led_blu, HIGH);
    digitalWrite(led_grn, HIGH);
    digitalWrite(led_ylw, LOW);
    digitalWrite(led_red, LOW);
  }
  else if (out_val == 6)
  {
    digitalWrite(led_wht, HIGH);
    digitalWrite(led_blu, HIGH);
    digitalWrite(led_grn, HIGH);
    digitalWrite(led_ylw, HIGH);
    digitalWrite(led_red, LOW);
  }
  else if (out_val == 7)
  {
    digitalWrite(led_wht, HIGH);
    digitalWrite(led_blu, HIGH);
    digitalWrite(led_grn, HIGH);
    digitalWrite(led_ylw, HIGH);
    digitalWrite(led_red, HIGH);
  }

}

void P_5()
{
  dato = analogRead(sensor);
  float temp = steinhart(dato);
  int out_val = map(temp, 25, 150, 2, 7);
  Serial.print(temp);
  Serial.print("   ");
  Serial.println(out_val);

  if (out_val == 2)
  {
    digitalWrite(led_wht, LOW);
    digitalWrite(led_blu, LOW);
    digitalWrite(led_grn, LOW);
    digitalWrite(led_ylw, LOW);
    digitalWrite(led_red, LOW);
  }
  else if (out_val == 3)
  {
    digitalWrite(led_wht, HIGH);
    digitalWrite(led_blu, LOW);
    digitalWrite(led_grn, LOW);
    digitalWrite(led_ylw, LOW);
    digitalWrite(led_red, LOW);
  }
  else if (out_val == 4)
  {
    digitalWrite(led_wht, HIGH);
    digitalWrite(led_blu, HIGH);
    digitalWrite(led_grn, LOW);
    digitalWrite(led_ylw, LOW);
    digitalWrite(led_red, LOW);
  }
  else if (out_val == 5)
  {
    digitalWrite(led_wht, HIGH);
    digitalWrite(led_blu, HIGH);
    digitalWrite(led_grn, HIGH);
    digitalWrite(led_ylw, LOW);
    digitalWrite(led_red, LOW);
  }
  else if (out_val == 6)
  {
    digitalWrite(led_wht, HIGH);
    digitalWrite(led_blu, HIGH);
    digitalWrite(led_grn, HIGH);
    digitalWrite(led_ylw, HIGH);
    digitalWrite(led_red, LOW);
  }
  else if (out_val == 7)
  {
    digitalWrite(led_wht, HIGH);
    digitalWrite(led_blu, HIGH);
    digitalWrite(led_grn, HIGH);
    digitalWrite(led_ylw, HIGH);
    digitalWrite(led_red, HIGH);
  }

}

void P_6()
{
  dato = analogRead(sensor);
  float temp = steinhart(dato);
  int out_val = map(temp, 26, 35, 2, 7);

  Serial.println(temp);
  //Serial.print("   ");
  //Serial.print(maxim);
  //Serial.print("   ");
  //Serial.println(minim);

  //if (temp > maxim) { maxim = temp;}
  //if (temp < minim) { minim = temp;}


  if (out_val == 2)
  {
    digitalWrite(led_wht, LOW);
    digitalWrite(led_blu, LOW);
    digitalWrite(led_grn, LOW);
    digitalWrite(led_ylw, LOW);
    digitalWrite(led_red, LOW);
  }
  else if (out_val == 3)
  {
    digitalWrite(led_wht, HIGH);
    digitalWrite(led_blu, LOW);
    digitalWrite(led_grn, LOW);
    digitalWrite(led_ylw, LOW);
    digitalWrite(led_red, LOW);
  }
  else if (out_val == 4)
  {
    digitalWrite(led_wht, HIGH);
    digitalWrite(led_blu, HIGH);
    digitalWrite(led_grn, LOW);
    digitalWrite(led_ylw, LOW);
    digitalWrite(led_red, LOW);
  }
  else if (out_val == 5)
  {
    digitalWrite(led_wht, HIGH);
    digitalWrite(led_blu, HIGH);
    digitalWrite(led_grn, HIGH);
    digitalWrite(led_ylw, LOW);
    digitalWrite(led_red, LOW);
  }
  else if (out_val == 6)
  {
    digitalWrite(led_wht, HIGH);
    digitalWrite(led_blu, HIGH);
    digitalWrite(led_grn, HIGH);
    digitalWrite(led_ylw, HIGH);
    digitalWrite(led_red, LOW);
  }
  else if (out_val == 7)
  {
    digitalWrite(led_wht, HIGH);
    digitalWrite(led_blu, HIGH);
    digitalWrite(led_grn, HIGH);
    digitalWrite(led_ylw, HIGH);
    digitalWrite(led_red, HIGH);
  }
}
