#include "NotGate.h"
#include <iostream>

NotGate::NotGate(std::string n) : Gate(n) {
    m_inputs.resize(1, nullptr);
    std::cout << "[" << m_name << "] NOT-Gatter aktiviert" << std::endl;
}

void NotGate::evaluate() {
    if (m_isCalculated) return;
    if (m_inputs[0]) {
        m_inputs[0]->evaluate();
        m_output = !m_inputs[0]->getOutput();
    } else {
        std::cerr << "FEHLER: NOT-Gatter [" << m_name << "] hat unverbundene Pins!" << std::endl;
        m_output = false;
    }
    m_isCalculated = true;
}

void NotGate::printState() const {
    bool a = m_inputs[0] ? m_inputs[0]->getOutput() : false;
    std::cout << "NotGate [" << m_name << ": Input=" << a
              << "] => Output=" << m_output << std::endl;
}
