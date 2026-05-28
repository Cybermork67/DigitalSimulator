#include "OrGate.h"
#include <iostream>

OrGate::OrGate(std::string n) : Gate(n) {
    m_inputs.resize(2); // Das OR-Gatter hat exakt 2 Eingangs-Pins
    std::cout << "[" << name << "] OR-Gatter aktiviert" << std::endl;
}

bool OrGate::evaluate() {
    m_output = m_inputs[0] || m_inputs[1];
    return m_output;
}

void OrGate::printState() const {
    std::cout << "OrGate [" << name << ": A=" << (m_inputs[0] ? 1 : 0)
              << ", B=" << (m_inputs[1] ? 1 : 0)
              << "] => Output=" << (m_output ? 1 : 0) << std::endl;
}
