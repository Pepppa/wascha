int last_decision = NODIR;

int N_ONE = 0; // left, forward
int N_TWO = 1; // right, round
int num_turn[] = {0,0};

int num_go[] = {0,0};

int decide_movement()
{
  int pos=0;
  int dir=0;
  
  if (num_go[N_ONE] == 0 && num_go[N_TWO] == 0)
  {
    // first time we're here
    int N = random(0,1);
    if (N)
    {
        pos = N_ONE;
        dir = FORWARD;
    }
    else
    {
        pos = N_TWO;
        dir = RIGHT;
    }
  }
  else
  {
    if (num_go[N_ONE] != 0)
    {
        pos = N_ONE;
        dir = FORWARD;
    }
    else
    {
        pos = N_TWO;
        dir = RIGHT;
    }
    int cur_num = num_go[pos];
    if (cur_num > 10)
    {
      // switch to opposite direction
      pos = !pos;
      //dir = !dir;
      // after change - just random change direction
      dir = RANDOM_ROUND;
    }      
  }
  
  num_go[pos]++;
  num_go[!pos] = 0;
  Serial.print("decided direction: ");
  Serial.println(dir);
  return dir;
}

int decide_turn() 
{
  int pos=0;
  int dir=0;
  
  if (num_turn[N_ONE] == 0 && num_turn[N_TWO] == 0)
  {
    // first time we're here
    int N = random(0,1);
    if (N)
    {
        pos = N_ONE;
        dir = LEFT;
    }
    else
    {
        pos = N_TWO;
        dir = RIGHT;
    }
  }
  else
  {
    if (num_turn[N_ONE] != 0)
    {
        pos = N_ONE;
        dir = LEFT;
    }
    else
    {
        pos = N_TWO;
        dir = RIGHT;
    }
    int cur_num = num_turn[pos];
    if (cur_num > 5)
    {
      // switch to opposite direction
      pos = !pos;
      dir = !dir;
    }      
  }
  
  num_turn[pos]++;
  num_turn[!pos] = 0;
  return dir;
}
