#include <Keyboard.h>
#include <Mouse.h>

#define BUTTON_PIN 2

char ctrlKey = KEY_LEFT_CTRL;  

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  // initialize control over the keyboard:
  Keyboard.begin();
  Mouse.begin();
  
}

void loop(){
  if (digitalRead(BUTTON_PIN)) {
    // do nothing until pin 2 goes low
    delay(50);
	}
	else {
	raceReset();
  }
}
void raceReset(){
  //resets AC to start
   delay(10);
	for (uint8_t i = 0; i < 16; i++){ // Arduino is stupid, so we have to loop
		Mouse.move(-127,-127,0); // sets back to upper left corner 
    }
	delay(10);
	Keyboard.press(0x80); // left ctrlkey
	delay(50);
	Keyboard.press('o');
	delay(20);
  Keyboard.releaseAll();
  delay(1000); // wait time for game to reset
	Mouse.move(20,65,0);
	delay(5);
	Mouse.click();
	delay(10);
		for (uint8_t i = 0; i < 16; i++){ // Arduino is stupid, so we have to loop
		Mouse.move(-127,127,0); // sets back to upper left corner 
		}
    Keyboard.releaseAll();              /// Changes View to driver
      delay(50);
	  Keyboard.press(KEY_F6);
      delay(50);
      Keyboard.releaseAll();
  delay(1000);
}
