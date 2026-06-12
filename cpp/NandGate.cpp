#include "NandGate.h"
#include <iostream>

NandGate::NandGate(std::string n) : Gate(n) {
    m_inputs.resize(2, nullptr);
    std::cout << "[" << m_name << "] NAND-Gatter aktiviert" << std::endl;
}

void NandGate::evaluate() {
    if (m_isCalculated) return;
    if (m_inputs[0] && m_inputs[1]) {
        m_inputs[0]->evaluate();
        m_inputs[1]->evaluate();
        m_output = !(m_inputs[0]->getOutput() && m_inputs[1]->getOutput());
    } else {
        std::cerr << "FEHLER: NAND [" << m_name << "] hat unverbundene Pins!" << std::endl;
        m_output = false;
    }
    m_isCalculated = true;
}

void NandGate::printState() const {
    bool a = m_inputs[0] ? m_inputs[0]->getOutput() : false;
    bool b = m_inputs[1] ? m_inputs[1]->getOutput() : false;
    std::cout << "NandGate [" << m_name << ": A=" << a << " B=" << b
              << "] => " << m_output << std::endl;
}
