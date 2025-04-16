void setupButton(){
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
}
void loopButton(){
  if(digitalRead(2) == 1)
  {
    buttonMode++;
    if(buttonMode > 5){
      buttonMode = 0;
    }
   
  }
  if(buttonMode == 1 && digitalRead(3) == 1){
    hour++;
    if(hour > 24){
      hour = 0;
    }
    clock.setDateTime(2016, 9, 15, hour, 0, 0);
  }
  if(buttonMode == 1 && digitalRead(4) == 1){
    hour--;
    if(hour < 0){
      hour = 24;
    }
    clock.setDateTime(2016, 9, 15, hour, 0, 0);
  }
  if(buttonMode == 2 && digitalRead(3) == 1){
      minute++;
      if(minute == 60){
        minute = 0;
        hour++;
      }
    clock.setDateTime(2016, 9, 15, hour, minute, 0);
    }
    if(buttonMode == 2 && digitalRead(4) == 1){
      minute--;
      if(minute < 0){
        minute = 59;
        hour--;
      }
    clock.setDateTime(2016, 9, 15, hour, minute, 0);
    }
    if(buttonMode == 3 && digitalRead(3) == 1){
      day++;
      if(day > 31 && month == month + 2){
        day = 1;
        month++;
      }
      if(month = 2 && day > 28){
        day = 1;
        month++;
      }
    clock.setDateTime(2016, 9, day, hour, minute, 0);
    }
    if(buttonMode == 3 && digitalRead(4) == 1){
      day--;
      if(day < 1){
        day = 31;
        month--;
      }
    clock.setDateTime(2016, 9, day, hour, minute, 0);
    }
    if(buttonMode == 4 && digitalRead(3) == 1){
      month++;
      if(month > 12){
        month = 1;
        year++;
      }
    clock.setDateTime(2016, month, day, hour, minute, 0);
    }
    if(buttonMode == 4 && digitalRead(4) == 1){
      month--;
      if(month < 1){
        month = 12;
        year--;
      }
    clock.setDateTime(2016, month, day, hour, minute, 0);
    }
    if(buttonMode == 5 && digitalRead(3) == 1){
      year++;
    clock.setDateTime(year, month, day, hour, minute, 0);
    }
    if(buttonMode == 5 && digitalRead(4) == 1){
      year--;
    clock.setDateTime(year, month, day, hour, minute, 0);
    }
    
    
  Serial.print(buttonMode);
  Serial.print(" ");
  Serial.println(hour);
}
