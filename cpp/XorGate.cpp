#include "XorGate.h"
#include <iostream>

XorGate::XorGate(std::string n) : Gate(n, 2) {
    std::cout << "[" << name << "] XOR-Gatter aktiviert" << std::endl;
}

bool XorGate::evaluate() {
    output = (inputs[0] && !inputs[1]) || (!inputs[0] && inputs[1]);
    return output;
}

void XorGate::printState() const {
    std::cout << "XorGate [" << name << ": A=" << (inputs[0] ? 1 : 0)
              << ", B=" << (inputs[1] ? 1 : 0)
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}
