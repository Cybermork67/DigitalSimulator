#include "XorGate.h"
#include <iostream>

XorGate::XorGate(std::string n) : Gate(n) {
    m_inputs.resize(2, nullptr);
    std::cout << "[" << m_name << "] XOR-Gatter aktiviert" << std::endl;
}

void XorGate::evaluate() {
    if (m_isCalculated) return;
    if (m_inputs[0] && m_inputs[1]) {
        m_inputs[0]->evaluate();
        m_inputs[1]->evaluate();
        bool a = m_inputs[0]->getOutput();
        bool b = m_inputs[1]->getOutput();
        m_output = (a && !b) || (!a && b);
    } else {
        std::cerr << "FEHLER: XOR-Gatter [" << m_name << "] hat unverbundene Pins!" << std::endl;
        m_output = false;
    }
    m_isCalculated = true;
}

void XorGate::printState() const {
    bool a = m_inputs[0] ? m_inputs[0]->getOutput() : false;
    bool b = m_inputs[1] ? m_inputs[1]->getOutput() : false;
    std::cout << "XorGate [" << m_name << ": A=" << a << ", B=" << b
              << "] => Output=" << m_output << std::endl;
}
