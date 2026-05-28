#include "AndGate.h"
#include <iostream>

AndGate::AndGate(std::string n) : Gate(n) {
    m_inputs.resize(2); // Das AND-Gatter hat exakt 2 Eingangs-Pins
    std::cout << "[" << name << "] AND-Gatter aktiviert" << std::endl;
}

bool AndGate::evaluate() {
    m_output = m_inputs[0] && m_inputs[1];
    return m_output;
}

void AndGate::printState() const {
    std::cout << "AndGate [" << name << ": A=" << (m_inputs[0] ? 1 : 0)
              << ", B=" << (m_inputs[1] ? 1 : 0)
              << "] => Output=" << (m_output ? 1 : 0) << std::endl;
}
