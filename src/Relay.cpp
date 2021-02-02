#include "Relay.h"

Relay::Relay(int pin, char name[]) {
    this->pin = pin;
    strcpy(this->whoami, name);
    pinMode(this->pin, OUTPUT);
}

void Relay::enable() {
    char buffer[50] = {0,};
    sprintf(buffer, "Put LOW to pin %d; relay %s.", this->pin, this->whoami);
    Serial.println(buffer);
    digitalWrite(this->pin, LOW);
}

void Relay::disable() {
    char buffer[50] = {0,};
    sprintf(buffer, "Put HIGH to pin %d; relay %s.", this->pin, this->whoami);
    Serial.println(buffer);
    digitalWrite(this->pin, HIGH);
}