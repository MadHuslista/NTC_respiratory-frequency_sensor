#include "Thread_manage.hpp"


int LED_1 = 7;
int LED_2 = 3;

void callthread_1()
{
  static bool ledstatus = false;
  ledstatus = !ledstatus;

  digitalWrite(LED_1, ledstatus);

  Serial.print("COOL! I0m running on: ");
  Serial.print(millis());
  Serial.println("This is thread_1");
}

void callthread_2()
{
  static bool ledstatus = false;
  ledstatus = !ledstatus;

  digitalWrite(LED_2, ledstatus);

  Serial.print("COOL! I0m running on: ");
  Serial.print(millis());
  Serial.println("This is thread_2");
}
