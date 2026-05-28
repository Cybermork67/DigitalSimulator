#include "NandGate.h"
#include <iostream>

NandGate::NandGate(std::string n)
    : Gate(n), andGate(n + "-AND"), notGate(n + "-NOT") {
    m_inputs.resize(2); // Das NAND-Gatter hat exakt 2 Eingangs-Pins
    std::cout << "[" << name << "] NAND-Gatter aktiviert (Komposition: AND + NOT)" << std::endl;
}

void NandGate::setInput(int port, int val) {
    Gate::setInput(port, val);
    andGate.setInput(port, val);
}

bool NandGate::evaluate() {
    bool andResult = andGate.evaluate();
    notGate.setInput(0, andResult ? 1 : 0);
    m_output = notGate.evaluate();
    return m_output;
}

void NandGate::printState() const {
    std::cout << "NandGate [" << name << ": A=" << (m_inputs[0] ? 1 : 0)
              << ", B=" << (m_inputs[1] ? 1 : 0)
              << "] => Output=" << (m_output ? 1 : 0) << std::endl;
}
