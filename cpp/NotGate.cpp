#include "NotGate.h"
#include <iostream>

NotGate::NotGate(std::string n) : Gate(n) {
    std::cout << "[" << name << "] NOT-Gatter aktiviert" << std::endl;
}

void NotGate::setInput(int port, int val) {
    if (port != 0) {
        std::cout << "[" << name << " WARNUNG] NOT-Gatter hat nur Port 0!" << std::endl;
        return;
    }
    Gate::setInput(0, val);
}

bool NotGate::evaluate() {
    output = !inA;
    return output;
}

void NotGate::printState() const {
    std::cout << "NotGate [" << name << ": Input=" << (inA ? 1 : 0) 
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}
