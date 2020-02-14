// interface functions

void forward(int N) {
  set_whell("left", "forward");
  set_whell("right", "forward");
  delay(N);
}

void backward(int N) {
  set_whell("left", "backward");
  set_whell("right", "backward");
  delay(N);
}

void stop(int N) {
  set_whell("left", "stop");
  set_whell("right", "stop");
  delay(N); 
}

void turn_left(int N) {
  set_whell("left", "forward");
  set_whell("right", "backward");
  delay(N);
}

void turn_right(int N) {
  set_whell("right", "forward");
  set_whell("left", "backward");
  delay(N);
}


