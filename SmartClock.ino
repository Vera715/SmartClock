#include "VariablesSettings.h"
#include "Welcome.h"
#include "TimeControl.h"
#include "ButtonSettings.h"
#include "OledControl.h"

void setup() {
  Serial.begin(9600);
  setupButton();
  allPictures();
  setupTime();


}

void loop() {
  loopButton();
  loopTime();
  loopOled();

}
