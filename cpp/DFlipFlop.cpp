#include "DFlipFlop.h"
#include <iostream>

DFlipFlop::DFlipFlop(std::string n) : Gate(n) {
    m_inputs.resize(1, nullptr);
    m_storedState = false;
    std::cout << "[" << m_name << "] D-Flip-Flop aktiviert (1 Pin, initial=0)" << std::endl;
}

// FIREWALL: Kein rekursiver evaluate()-Aufruf auf dem Input!
// Gibt den alten gespeicherten Zustand zurueck (Lese-Phase).
void DFlipFlop::evaluate() {
    if (m_isCalculated) return;
    m_output = m_storedState;
    m_isCalculated = true;
}

// Schreib-Phase: liest stabilen Input-Wert und speichert ihn im Tresor.
void DFlipFlop::onClockTick() {
    bool inputValue = m_inputs[0] ? m_inputs[0]->getOutput() : false;
    m_storedState = inputValue;
}

void DFlipFlop::printState() const {
    std::string pin = m_inputs[0] ? "verbunden" : "FLOATING";
    std::cout << "DFlipFlop [" << m_name << ": Input=" << pin
              << ", Stored=" << m_storedState
              << "] => Output=" << m_output << std::endl;
}

DFlipFlop::~DFlipFlop() {
    std::cout << "[DESTRUKTOR] D-Flip-Flop: " << m_name << std::endl;
}
