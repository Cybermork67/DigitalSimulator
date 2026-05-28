#include "NotGate.h"
#include <iostream>

NotGate::NotGate(std::string n) : Gate(n, 1) {
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
    output = !inputs[0];
    return output;
}

void NotGate::printState() const {
    std::cout << "NotGate [" << name << ": Input=" << (inputs[0] ? 1 : 0)
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}
