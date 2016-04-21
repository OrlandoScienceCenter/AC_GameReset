#include <Keyboard.h>

#define BUTTON_PIN 2

char ctrlKey = KEY_LEFT_CTRL;  

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop(){
  if (digitalRead(BUTTON_PIN)) {
    // do nothing until pin 2 goes low
    delay(250);
	}
	else {
	raceReset();
  }
}
void raceReset(){
  //resets AC to start
	  Keyboard.press(ctrlKey);
	  Keyboard.press('o');
  //Activates AutoHotKeyScript to click mouse on start race button
	  Keyboard.press(ctrlKey);
	  Keyboard.press(KEY_F12);
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
}
