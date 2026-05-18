#include "NotGate.h"
#include <iostream>

NotGate::NotGate(std::string n) : Component(n) {
    std::cout << "[" << name << "] NOT-Gatter aktiviert" << std::endl;
}

void NotGate::setInputB(int /* val */) {
    std::cout << "[" << name << " WARNUNG] NOT-Gatter hat keinen Eingang B!" << std::endl;
    std::cout << "           Nutzen Sie setInputA() für den einzigen Eingang." << std::endl;
}

bool NotGate::evaluate() {
    output = !inA;
    return output;
}

void NotGate::printState() const {
    std::cout << "NotGate [" << name << ": Input=" << (inA ? 1 : 0) 
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}
