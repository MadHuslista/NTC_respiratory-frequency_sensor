#include <Thread.h>
#include <ThreadController.h>

ThreadController controll = ThreadController();

Thread Thread_1 = Thread();
Thread Thread_2 = Thread(); 

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


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(LED_1, OUTPUT);
pinMode(LED_2, OUTPUT);

Thread_1.onRun(callthread_1);
Thread_1.setInterval(500);

Thread_2.onRun(callthread_2);
Thread_2.setInterval(300);

controll.add(&Thread_1);
controll.add(&Thread_2);


}

void loop() {
  // put your main code here, to run repeatedly:
controll.run();

}
