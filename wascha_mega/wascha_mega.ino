
//enum dirs {NODIR, STOP, FORWARD, BACKWARD, LEFT, RIGHT};

int NODIR = 0;
int STOP = 1;
int FORWARD = 2;
int BACKWARD = 3;
int LEFT = 4;
int RIGHT = 5;
int RANDOM_ROUND = 6;



int beep_pin = 50;

int wheels_block = 42;


void setup() {                
  stop(0);
  detector_init();
  Serial.begin (9600);

}

void beep() {
  digitalWrite(beep_pin, HIGH);
  delay(50);
  digitalWrite(beep_pin, LOW);  
}

boolean total_block(){
    pinMode(wheels_block, INPUT);
    digitalRead(wheels_block) != LOW;
}

void loop() {
  
//  if (total_block) {
//    stop(1000);
//  }
//  else
//  {
    if (detect()){
      // something blocks movement
      // let's go a bit back and then
      // turn to some side
      go(BACKWARD, 300);
      turn(decide_turn(), 300);
    }
    else
    {
      // nothing blocks us.
      // what should we do?
      go(decide_movement(), 200);
    }     
//  }
}


