#include "NotGate.h"
#include <iostream>

NotGate::NotGate(std::string n) : Gate(n) {
    m_inputs.resize(1); // Das NOT-Gatter hat exakt 1 Eingangs-Pin
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
    m_output = !m_inputs[0];
    return m_output;
}

void NotGate::printState() const {
    std::cout << "NotGate [" << name << ": Input=" << (m_inputs[0] ? 1 : 0)
              << "] => Output=" << (m_output ? 1 : 0) << std::endl;
}
