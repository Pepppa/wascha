//
// Created by xshiolg on 2/3/21.
//

#include "ElectromagneticRelay.h"

ElectromagneticRelay::ElectromagneticRelay(int pin, char name[]) : Relay(pin, name) {;};

void ElectromagneticRelay::enable() {
    char buffer[50] = {0,};
    sprintf(buffer, "ElectromagneticRelay enabling: Put LOW to pin %d; relay %s.", this->pin, this->whoami);
    Serial.println(buffer);
    digitalWrite(this->pin, LOW);
}

void ElectromagneticRelay::disable() {
    char buffer[50] = {0,};
    sprintf(buffer, "ElectromagneticRelay disabling: Put HIGH to pin %d; relay %s.", this->pin, this->whoami);
    Serial.println(buffer);
    digitalWrite(this->pin, HIGH);
}