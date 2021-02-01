#include "helper.h"
#include "Wheel.h"

int DELAY = 2000;
Wheel* wheel1 = nullptr;

void init_all() {
    wheel1 = new Wheel(3, 4, 5, 6);
}

void turn_next() {
    wheel1->forward();
    delay(DELAY);
    wheel1->backward();
    delay(DELAY);
    wheel1->stop();
    delay(DELAY*2);

}
