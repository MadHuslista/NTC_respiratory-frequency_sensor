
#include "Activities.hpp"
#include "Tools.hpp"
#include "DFT.hpp"


void P_1()
{
  sensor_val = analogRead(sensor_read);
  float temp = steinhart(sensor_val);
  Serial.print(sensor_val);
  Serial.print("   ");
  Serial.print(temp);
  Serial.println(" °C");
}

void P_4()
{
  sensor_val = analogRead(sensor_read);
  float temp = steinhart(sensor_val);
  out_val = map(temp, 25, 34, 2, 7);
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
  sensor_val = analogRead(sensor_read);
  float temp = steinhart(sensor_val);
  out_val = map(temp, 25, 150, 2, 7);
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
  sensor_val = analogRead(sensor_read);
  float temp = steinhart(sensor_val);
  out_val = float_map(temp, 27, 30, 2, 7);

  Serial.print(temp);
  Serial.print("   ");
  Serial.print(maxim);
  Serial.print("   ");
  Serial.println(minim);

  if (temp > maxim) { maxim = temp;}
  if (temp < minim) { minim = temp;}


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



void P_7()
{
  if (Flag == 0)
  {
    current_time = millis();
    if (current_time - prev_time >= interval)
    {
      dato = analogRead(sensor_read);
      prev_time = current_time;
      sign[i] = dato;
      float temp = steinhart(dato)/10;
      
      Serial.print("READING   ");
      Serial.print(dato);
      Serial.print("  ");
      Serial.println(temp);
      
      //Serial.print(temp);
      //Serial.print(",");
      //Serial.println(0);
      
      i = i + 1;
      if (i > (N - 1))
      {
        i = 0;
        Flag = 1;

      }
    }
  }

  
  else if (Flag == 1)
  {
    Serial.println("DFT");
    detect_freq(sign);
    Serial.println("DFT - END");

    //dft_results = dft(sign);
    //avg_results = avg(dft_results);
    
    Flag = 2;
  }


  
  else if (Flag == 2)
  {
    current_time = millis();
    if (current_time - prev_time >= interval)
    {
     prev_time = current_time;
     //Serial.print(dft_results[h]);
     //Serial.print(",");
     //Serial.println(avg_results[h]);
     
     //Serial.println("PRITING DFT");
     h = h + 1;
     if (h > (N / 2 - 1)) 
     {
      h = 0;
      Flag = 0;
     }
    }
  }


}
