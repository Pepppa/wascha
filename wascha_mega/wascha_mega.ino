

int trig = 53;
int echo = 52;
int beep_pin = 50;

boolean next_left = true;
int num_to_one_side = 0;


// the setup routine runs once when you press reset:
void setup() {                
  stop(0);
  Serial.begin (9600);
  pinMode(trig, OUTPUT);
  pinMode(beep_pin, OUTPUT);
  pinMode(echo, INPUT);
}

void beep() {
  digitalWrite(beep_pin, HIGH);
  delay(50);
  digitalWrite(beep_pin, LOW);  
}

// the loop routine runs over and over again forever:
void loop() {

  if (detect() ){
    beep();
    if (num_to_one_side > 4) {
      next_left = !next_left;
      num_to_one_side = 0;
    }
    else {
      num_to_one_side++;
    }
    backward(500);
    if (next_left){
      turn_left(300);
    }
    else{
      turn_right(300);
    }
  }
  else
  {
    num_to_one_side=0;
    forward(100);
  }
//  left_backward(); 
//  delay(1000);
  
}

boolean detect() {
  long duration, cm;
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH);
  cm = (duration/2) / 29.1;
  return (cm < 20);  
}









