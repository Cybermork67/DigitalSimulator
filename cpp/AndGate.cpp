#include "AndGate.h"
#include <iostream>

AndGate::AndGate(std::string n) : Gate(n) {
    std::cout << "[" << name << "] AND-Gatter aktiviert" << std::endl;
}

bool AndGate::evaluate() {
    output = inA && inB;
    return output;
}

void AndGate::printState() const {
    std::cout << "AndGate [" << name << ": A=" << (inA ? 1 : 0) 
              << ", B=" << (inB ? 1 : 0) 
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}
