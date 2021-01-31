int trig = 53;
int echo = 52;

int last_cm = 0;
int stop_periods = 0;

void detector_init() 
{
  pinMode(trig, OUTPUT);
  pinMode(beep_pin, OUTPUT);
  pinMode(echo, INPUT);
}

boolean detect() {
  int cm = calculate_cm();
  boolean is_detected = (is_not_changed_for_a_while(cm) || is_too_small(cm) || is_to_high(cm));
  return is_detected; 
}


int calculate_cm()
{
  long duration, cm;
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH);
  cm = (duration/2) / 29.1;
  Serial.print("Duration: ");
  Serial.println(cm);
  return cm;
}

boolean is_too_small(int cm)
{
    return cm < 20;
}

boolean is_to_high(int cm)
{
  // Let's determine it's a reation to fiber
  return cm > 2000;
  //return false;
}

boolean is_not_changed_for_a_while(int cm)
{
  int diff = abs(last_cm - cm);
  last_cm = cm;
  if (diff < 3)
  {
    stop_periods++;
    return stop_periods > 5;
  }
  else
  {
    stop_periods = 0;
    return false;
  }
}
