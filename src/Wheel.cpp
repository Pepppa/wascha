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

void Wheel::forward() {
   polarity_1() ;
};

void Wheel::backward() {
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