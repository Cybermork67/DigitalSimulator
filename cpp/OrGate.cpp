#include "OrGate.h"
#include <iostream>

OrGate::OrGate(std::string n) : Gate(n, 2) {
    std::cout << "[" << name << "] OR-Gatter aktiviert" << std::endl;
}

bool OrGate::evaluate() {
    output = inputs[0] || inputs[1];
    return output;
}

void OrGate::printState() const {
    std::cout << "OrGate [" << name << ": A=" << (inputs[0] ? 1 : 0)
              << ", B=" << (inputs[1] ? 1 : 0)
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}
