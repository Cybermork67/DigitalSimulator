#include "XorGate.h"
#include <iostream>

XorGate::XorGate(std::string n) : Gate(n) {
    std::cout << "[" << name << "] XOR-Gatter aktiviert" << std::endl;
}

bool XorGate::evaluate() {
    output = (inA && !inB) || (!inA && inB);
    return output;
}

void XorGate::printState() const {
    std::cout << "XorGate [" << name << ": A=" << (inA ? 1 : 0) 
              << ", B=" << (inB ? 1 : 0) 
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}
