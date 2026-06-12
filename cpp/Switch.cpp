#include "Switch.h"
#include <iostream>

Switch::Switch(std::string n) : Gate(n) {
    m_inputs.resize(0);
    std::cout << "[" << m_name << "] Switch aktiviert" << std::endl;
}

void Switch::setState(bool state) {
    m_output = state;
}

void Switch::evaluate() {
    if (m_isCalculated) return;
    m_isCalculated = true;
    // m_output wird direkt durch setState() gesetzt
}

void Switch::printState() const {
    std::cout << "Switch [" << m_name << "] => " << m_output << std::endl;
}
