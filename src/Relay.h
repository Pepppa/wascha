//
// Created by xshiolg on 2/2/21.
//

#ifndef WASHA_RELAY_H
#define WASHA_RELAY_H

#include "helper.h"

/*
 * Relay is open when LOW voltage on pin
 */

class Relay {
public:
    Relay(int pin, char name[]) ;
    ~Relay() {;} ;
    void enable();
    void disable();

private:
    int pin;
    char whoami[4] = {0,};
};


#endif //WASHA_RELAY_H
