// interface functions

int current_direction = NODIR; 

void go( int direction, int N)
{
//  switch(direction){
//    case FORWARD:
//        forward(N);
//        break;
//    case BACKWARD:
//        backward(N);
//        break;
//    default:
//        stop(N);
//  }
  if (direction == FORWARD){
    forward(N);
  } else if (direction == BACKWARD){
    backward(N);
  } else {
    stop(N);
  }
}

void turn(int direction, int N)
{
//  switch (direction) {
//    case LEFT:
//        turn_left(N);
//        break;
//    case RIGHT:
//        turn_right(N);
//        break;
//    default:
//        stop(N);
//  }
  if (direction == LEFT){
    turn_left(N);
  } else if (direction == RIGHT){
    turn_right(N);
  } else {
    stop(N);
  }
}

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


