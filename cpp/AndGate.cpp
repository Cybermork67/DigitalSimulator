#include "AndGate.h"
#include <iostream>

AndGate::AndGate(std::string n) : Gate(n, 2) {
    std::cout << "[" << name << "] AND-Gatter aktiviert" << std::endl;
}

bool AndGate::evaluate() {
    output = inputs[0] && inputs[1];
    return output;
}

void AndGate::printState() const {
    std::cout << "AndGate [" << name << ": A=" << (inputs[0] ? 1 : 0)
              << ", B=" << (inputs[1] ? 1 : 0)
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}
