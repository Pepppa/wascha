int last_decision = NODIR;

int N_LEFT = 0;
int N_RIGHT = 1;
int num_turn[] = {0,0};

int N_FORWARD = 0;
int N_ROUND = 1;
int num_go[] = {0,0};

int decide_turn() 
{
  int pos=0;
  int dir=0;
  
  if (num_turn[N_LEFT] == 0 && num_turn[N_RIGHT] == 0)
  {
    // first time we're here
    int N = random(0,1);
    if (N)
    {
        pos = N_LEFT;
        dir = LEFT;
    }
    else
    {
        pos = N_RIGHT;
        dir = RIGHT;
    }
  }
  else
  {
    if (num_turn[N_LEFT] != 0)
    {
        pos = N_LEFT;
        dir = LEFT;
    }
    else
    {
        pos = N_RIGHT;
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
