#include "DFlipFlop.h"
#include <iostream>

DFlipFlop::DFlipFlop(std::string n) : Gate(n) {
    m_inputs.resize(1, nullptr);
    m_storedState = false;
    std::cout << "[" << m_name << "] D-Flip-Flop aktiviert (1 Pin, initial=0)" << std::endl;
}

// FIREWALL: Input wird NICHT evaluiert - verhindert Endlosrekursion bei Ringverkabelung
void DFlipFlop::evaluate() {
    if (m_isCalculated) return;
    m_output = m_storedState; // Gibt den alten gespeicherten Wert zurueck
    m_isCalculated = true;
}

// Schreib-Phase: liest stabilen Input-Wert und speichert ihn im Tresor
void DFlipFlop::onClockTick() {
    bool inputValue = m_inputs[0] ? m_inputs[0]->getOutput() : false;
    m_storedState = inputValue;
    std::cout << "[CLOCK] " << m_name << " speichert: " << inputValue << std::endl;
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
