/*
 * Four-relay scheme:
 *
 * W1----Wheel----W2
 * |\            /|
 * | \          / |
 * |  \        /  |
 * |   \      /   |
 * |    \    /    |
 * |     \  /     |
 * |      \/      |
 * |      /\      |
 * R1P   /  \    R2N
 * |   R2P  R1N   |
 * |   /      \   |
 * |  /        \  |
 * | /          \ |
 * |/            \|
 * |--(P)+  -(N)--|
 *
 * R1P is IN1
 * R2P is IN2
 * R1N is IN3
 * R2N is IN4
 */

#include "Wheel.h"

Wheel::Wheel(int pin1P, int pin2P, int pin1N, int pin2N) {
       this->R1N = new Relay(pin1N, "R1N");
       this->R2N = new Relay(pin2N, "R2N");
       this->R1P = new Relay(pin1P, "R1P");
       this->R2P = new Relay(pin2P, "R2P");
    }

Wheel::~Wheel() {
        delete R1N;
        delete R2N;
        delete R1P;
        delete R2P;
    }

void Wheel::forward() {
   Serial.println("inside forward");
   polarity_1() ;
};

void Wheel::backward() {
   Serial.println("inside backward");
   polarity_2() ;
};

void Wheel::stop() {
    this->R1N->disable();
    this->R2P->disable();
    this->R1P->disable();
    this->R2N->disable();
};

void Wheel::polarity_1() {
    this->R1N->disable();
    this->R2P->disable();
    this->R1P->enable();
    this->R2N->enable();
}

void Wheel::polarity_2() {
    this->R2N->disable();
    this->R1P->disable();
    this->R2P->enable();
    this->R1N->enable();
}