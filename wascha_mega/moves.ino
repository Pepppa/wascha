// interface functions

enum dirs {NODIR, STOP, FORWARD, BACKWARD, LEFT, RIGHT};

dirs current_direction = NODIR; 

void forward(int N) {
  if (current_direction != FORWARD)
  {
    set_whell("left", "forward");
    set_whell("right", "forward");
    current_direction = FORWARD;
  }
  delay(N);
}

void backward(int N) {
  if (current_direction != BACKWARD)
  {
    set_whell("left", "backward");
    set_whell("right", "backward");
    current_direction = BACKWARD;
  }
  delay(N);
}

void stop(int N) {
  if (current_direction != STOP)
  {
    set_whell("left", "stop");
    set_whell("right", "stop");
    current_direction = STOP;
  }
  delay(N); 
}

void turn_left(int N) {
  if (current_direction != LEFT)
  {
    set_whell("left", "forward");
    set_whell("right", "backward");
    current_direction = LEFT;
  }
  delay(N);
}

void turn_right(int N) {
  if (current_direction != RIGHT)
  {
    set_whell("right", "forward");
    set_whell("left", "backward");
    current_direction = RIGHT;
  }
  delay(N);
}


