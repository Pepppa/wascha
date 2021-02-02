#ifndef WASHA_WHEEL_H
#define WASHA_WHEEL_H

#include "helper.h"
#include "Relay.h"

class Wheel {

public:
    Wheel(int pin1P, int pin2P, int pin1N, int pin2N) ;
   ~Wheel() ;

    void forward() ;
    void backward() ;
    void stop() ;

private:
    Relay* R1P = nullptr; // relay 1 on board
    Relay* R2P = nullptr; // relay 2 on board
    Relay* R1N = nullptr; // relay 3 on board
    Relay* R2N = nullptr; // relay 4 on board

    void polarity_1(); // 1P --- 2N
    void polarity_2(); // 1N --- 2P

};


#endif //WASHA_WHEEL_H
