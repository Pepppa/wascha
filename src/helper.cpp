#include "helper.h"

std::vector<int> PINS = {3,7,10};
int DELAY = 500;


void init_all() {
    for (auto pin : PINS) {
        pinMode(pin, OUTPUT);
    }
}

void turn_next() {
    static int current_pos = 0;
    int max_pos = 2;

    digitalWrite(PINS[current_pos], HIGH);
    delay(DELAY);
    digitalWrite(PINS[current_pos], LOW);
    delay(DELAY);

    current_pos++;
    if (current_pos > PINS.size()) {
	    current_pos = 0;
    }
}
