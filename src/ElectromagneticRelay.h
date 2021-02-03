//
// Created by xshiolg on 2/3/21.
//

#ifndef WASHA_ELECTROMAGNETICRELAY_H
#define WASHA_ELECTROMAGNETICRELAY_H

#include "Relay.h"
#include "helper.h"

class ElectromagneticRelay : public  Relay {
public:
    ElectromagneticRelay(int pin, char name[]);
    virtual ~ElectromagneticRelay() {;};
    void enable();
    void disable();
};


#endif //WASHA_ELECTROMAGNETICRELAY_H
