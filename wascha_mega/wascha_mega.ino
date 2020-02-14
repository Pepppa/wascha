
int relley1 = 12;
int relley2 = 11;
int relley3 = 10;
int relley4 = 9;

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
      go_left(300);
    }
    else{
      go_right(300);
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


void forward(int N) {
  left_forward();
  right_forward();
  delay(N);
}

void backward(int N) {
  left_backward();
  right_backward();
  delay(N);
}

void stop(int N) {
  left_stop();
  right_stop();
  delay(N); 
}

void go_left(int N) {
  left_forward();
  right_backward();
  delay(N);
}

void go_right(int N) {
  right_forward();
  left_backward();
  delay(N);
}

void left_backward() {
  analogWrite(relley3, 255);   
  analogWrite(relley4, 0);
}

void left_forward() {
  analogWrite(relley3, 0);   
  analogWrite(relley4, 255);
}

void left_stop() {

  analogWrite(relley3, 0);
  analogWrite(relley4, 0);
}

void right_backward() {
  analogWrite(relley1, 255);   
  analogWrite(relley2, 0);
}

void right_forward() {
  analogWrite(relley1, 0);   
  analogWrite(relley2, 255);
}

void right_stop() {
  analogWrite(relley1, 0);   
  analogWrite(relley2, 0);
}







