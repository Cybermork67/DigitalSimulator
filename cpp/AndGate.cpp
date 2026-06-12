#include "AndGate.h"
#include <iostream>

AndGate::AndGate(std::string n) : Gate(n) {
    m_inputs.resize(2, nullptr);
    std::cout << "[" << m_name << "] AND-Gatter aktiviert" << std::endl;
}

void AndGate::evaluate() {
    if (m_isCalculated) return;
    if (m_inputs[0] && m_inputs[1]) {
        m_inputs[0]->evaluate();
        m_inputs[1]->evaluate();
        m_output = m_inputs[0]->getOutput() && m_inputs[1]->getOutput();
    } else {
        std::cerr << "FEHLER: AND-Gatter [" << m_name << "] hat unverbundene Pins!" << std::endl;
        m_output = false;
    }
    m_isCalculated = true;
}

void AndGate::printState() const {
    bool a = m_inputs[0] ? m_inputs[0]->getOutput() : false;
    bool b = m_inputs[1] ? m_inputs[1]->getOutput() : false;
    std::cout << "AndGate [" << m_name << ": A=" << a << ", B=" << b
              << "] => Output=" << m_output << std::endl;
}
