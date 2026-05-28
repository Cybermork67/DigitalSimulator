#include "XorGate.h"
#include <iostream>

XorGate::XorGate(std::string n) : Gate(n) {
    m_inputs.resize(2); // Das XOR-Gatter hat exakt 2 Eingangs-Pins
    std::cout << "[" << name << "] XOR-Gatter aktiviert" << std::endl;
}

bool XorGate::evaluate() {
    m_output = (m_inputs[0] && !m_inputs[1]) || (!m_inputs[0] && m_inputs[1]);
    return m_output;
}

void XorGate::printState() const {
    std::cout << "XorGate [" << name << ": A=" << (m_inputs[0] ? 1 : 0)
              << ", B=" << (m_inputs[1] ? 1 : 0)
              << "] => Output=" << (m_output ? 1 : 0) << std::endl;
}
