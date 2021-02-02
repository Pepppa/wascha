#include "helper.h"

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);
  Serial.print("Start");
  Serial.println();
  init_all();


}

// the loop routine runs over and over again forever:
void loop() {
    Serial.print("Turn next");
    Serial.println();
	turn_next();

}


