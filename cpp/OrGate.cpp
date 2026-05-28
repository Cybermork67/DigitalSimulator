#include "OrGate.h"
#include <iostream>

OrGate::OrGate(std::string n) : Gate(n) {
    std::cout << "[" << name << "] OR-Gatter aktiviert" << std::endl;
}

bool OrGate::evaluate() {
    output = inA || inB;
    return output;
}

void OrGate::printState() const {
    std::cout << "OrGate [" << name << ": A=" << (inA ? 1 : 0) 
              << ", B=" << (inB ? 1 : 0) 
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}
