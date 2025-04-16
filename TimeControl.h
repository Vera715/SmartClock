#include <Wire.h>
#include <DS3231.h>
unsigned long prev = 0;
unsigned long period = 1000;
DS3231 clock;
RTCDateTime dt;


void setupTime()
{
  Serial.println("Initialize DS3231");;
  clock.begin();
  clock.setDateTime(__DATE__, __TIME__);
}
void loopTime()
{
  unsigned long presentTime = millis();
  if (presentTime - prev > period)
  {
    prev = presentTime;
    dt = clock.getDateTime();
    hour = dt.hour;
    minute = dt.minute;
    second = dt.second;
//    Serial.print(hour);   Serial.print(":");
//    Serial.print(minute); Serial.print(":");
//    Serial.print(second); Serial.println("");

  }
}
