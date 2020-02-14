// 4-relleys based initialization

int relley_r_1 = 12; // relley #1
int relley_r_2 = 11; // relley #2
int relley_l_1 = 10; // relley #3
int relley_l_2 = 9;  // relley #4

int right_pins[] = {relley_r_1, relley_r_2};
int left_pins[]  = {relley_l_1, relley_l_2};

// LOW opens NC side of relley,
// HIGH opens NO side of relley
int NO = 255;
int NC = 0;

void  set_whell(char* side, char* direction) 
{
    static int map[] = {NC, NC};
    direction_to_pin_map(direction, map);
    do_set_whell(side_to_pins(side), map);
}

void do_set_whell(int pins[], int map[]) 
{
  Serial.println("Ready to go through pins");
  
  for ( int i = 0; i <= 1; i++ )
  {
      Serial.print("Ready to analoWrite to ");
      Serial.print(pins[i]);
      Serial.print(" ");
      Serial.println(map[i]);
      analogWrite(pins[i], map[i]);
  }
}

int* side_to_pins(char* side) {
  if (strcmp(side, "left") == 0) {
    return left_pins;
  }
  else {
    // means "right"
    return right_pins;
  }
}

void direction_to_pin_map(char* direction, int map[]) {
  

  // NC is connected to (-),
  // NO is connected to (+)
  // Pins A and B of servo are connected to COM:
  // A to relley [1], B to relley [0]
  
  if (strcmp(direction, "forward") == 0)
  {
    // open path A(+) -> B(-)
    map[0] = NC;
    map[1] = NO;
  }
  else if (strcmp(direction, "backward") == 0)
  {
    // open path B(+) -> A(-)
    map[0] = NO;
    map[1] = NC;
  }
  else
  {
    // means "stop"
    // block paths A(0) -/- B(0)
    map[0] = NC;
    map[1] = NC;
  }
}
