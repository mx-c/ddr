#include <Keyboard.h>
#define BUF_LEN 128 
char BUFFER[BUF_LEN];

  unsigned int PIN_UP = 4;
  unsigned int PIN_RIGHT = 5;
  unsigned int PIN_DOWN = 6;
  unsigned int PIN_LEFT = 7;

  unsigned int PIN_ENTER = 8;
  unsigned int PINS [4] = {
    PIN_UP,
    PIN_RIGHT,
    PIN_DOWN,
    PIN_LEFT
  };


  unsigned int ARROW_UP = 106; // j
  unsigned int ARROW_RIGHT = 107; // k
  unsigned int ARROW_DOWN = 108; // l
  unsigned int ARROW_LEFT = 104; // h
  
  unsigned int ARROWS [4] = {
    ARROW_UP,
    ARROW_RIGHT,
    ARROW_DOWN,
    ARROW_LEFT
  };
  
  // vector is left, up, right, bottom
  unsigned int currentVector [4] = { LOW, LOW, LOW, LOW };
  unsigned int prevVector [4] = { LOW, LOW, LOW, LOW };


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  pinMode(PIN_UP, INPUT);
  pinMode(PIN_RIGHT, INPUT);
  pinMode(PIN_DOWN, INPUT);
  pinMode(PIN_LEFT, INPUT);
  pinMode(PIN_ENTER, INPUT);

  Serial.println("ready, loop starting");
}
unsigned int test = 0;
void loop() {
  bool change = false;
  for (int i = 0; i < 4; i++) {
    currentVector[i] = digitalRead(PINS[i]);
    if (currentVector[i] != prevVector[i]) {
      change = true;
      if (currentVector[i] == HIGH) {
        Keyboard.write(ARROWS[i]);
      } else {
        Keyboard.release(ARROWS[i]);
      }
      prevVector[i] = currentVector[i];
    }
  }
  // vector log
  if (change) {
    snprintf(
      BUFFER,
      sizeof(BUFFER),
      "(%d, %d, %d,%d) - %d",
      currentVector[0],
      currentVector[1],
      currentVector[2],
      currentVector[3],
      test
    );
    Serial.println(BUFFER);
    delay(200);
  }
}
