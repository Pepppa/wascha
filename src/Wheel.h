#ifndef WASHA_WHEEL_H
#define WASHA_WHEEL_H

#include "helper.h"

/*
 * Relay is open when ? voltage on pin
 */
struct Relay {
    Relay(int pin) {
       this->pin = pin;
       pinMode(this->pin, OUTPUT);
    };

    ~Relay() {;} ;

    int pin;
    void enable() {
        digitalWrite(this->pin, LOW);
    }
    void disable() {
        digitalWrite(this->pin, HIGH);
    }
};

class Wheel {


public:
    Wheel(int pin1P, int pin2P, int pin1N, int pin2N) {
       this->R1N = new Relay(pin1N);
       this->R2N = new Relay(pin2N);
       this->R1P = new Relay(pin1P);
       this->R2P = new Relay(pin2P);
    };

   ~Wheel() {
        delete R1N;
        delete R2N;
        delete R1P;
        delete R2P;
    };

    void forward() ;
    void backward() ;
    void stop() ;

private:
    Relay* R1N = nullptr;
    Relay* R1P = nullptr;
    Relay* R2N = nullptr;
    Relay* R2P = nullptr;

    void polarity_1();
    void polarity_2();

};


#endif //WASHA_WHEEL_H
