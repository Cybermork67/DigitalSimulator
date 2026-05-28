#include "NotGate.h"
#include <iostream>

NotGate::NotGate(std::string n) : Gate(n) {
    m_inputs.resize(1, nullptr); // Das NOT-Gatter hat exakt 1 Eingangs-Pin
    std::cout << "[" << name << "] NOT-Gatter aktiviert" << std::endl;
}

void NotGate::connectInput(int port, Gate* source) {
    if (port != 0) {
        std::cout << "[" << name << " WARNUNG] NOT-Gatter hat nur Port 0!" << std::endl;
        return;
    }
    Gate::connectInput(0, source);
}

bool NotGate::evaluate() {
    // Unverbundene Pins prüfen (Punkt 3: nullptr-Check)
    if (m_inputs[0] != nullptr) {
        bool val = m_inputs[0]->getOutput(); // Pull-Prinzip: Wert ziehen
        m_output = !val;
    } else {
        std::cerr << "FEHLER: NOT-Gatter hat unverbundene Pins!" << std::endl;
        m_output = false; // Sicherer Fallback
    }
    return m_output;
}

void NotGate::printState() const {
    bool a = (m_inputs[0] ? m_inputs[0]->getOutput() : false);
    std::cout << "NotGate [" << name << ": Input=" << (a ? 1 : 0)
              << "] => Output=" << (m_output ? 1 : 0) << std::endl;
}
