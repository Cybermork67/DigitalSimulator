#include "OrGate.h"
#include <iostream>

OrGate::OrGate(std::string n) : Gate(n) {
    m_inputs.resize(2, nullptr); // Das OR-Gatter hat exakt 2 Eingangs-Pins
    std::cout << "[" << name << "] OR-Gatter aktiviert" << std::endl;
}

bool OrGate::evaluate() {
    // Unverbundene Pins prüfen (Punkt 3: nullptr-Check)
    if (m_inputs[0] != nullptr && m_inputs[1] != nullptr) {
        bool valA = m_inputs[0]->getOutput(); // Pull-Prinzip: Wert ziehen
        bool valB = m_inputs[1]->getOutput();
        m_output = valA || valB;
    } else {
        std::cerr << "FEHLER: OR-Gatter hat unverbundene Pins!" << std::endl;
        m_output = false; // Sicherer Fallback
    }
    return m_output;
}

void OrGate::printState() const {
    bool a = (m_inputs[0] ? m_inputs[0]->getOutput() : false);
    bool b = (m_inputs[1] ? m_inputs[1]->getOutput() : false);
    std::cout << "OrGate [" << name << ": A=" << (a ? 1 : 0)
              << ", B=" << (b ? 1 : 0)
              << "] => Output=" << (m_output ? 1 : 0) << std::endl;
}
