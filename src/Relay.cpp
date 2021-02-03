#include "Relay.h"

Relay::Relay(int pin, char name[]) {
    this->pin = pin;
    strcpy(this->whoami, name);
    pinMode(this->pin, OUTPUT);
}

