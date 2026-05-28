#include "Switch.h"
#include <iostream>

Switch::Switch(std::string n) : Gate(n) {
    m_inputs.resize(0); // Der Schalter hat 0 Eingangs-Pins
    std::cout << "[" << name << "] Switch-Schalter aktiviert" << std::endl;
}

void Switch::connectInput(int port, Gate* source) {
    (void)port; (void)source;
    std::cerr << "[" << name << " WARNUNG] Switch hat keine Eingangs-Pins!" << std::endl;
}

void Switch::setState(bool state) {
    m_output = state;
}

bool Switch::evaluate() {
    return m_output;
}

void Switch::printState() const {
    std::cout << "Switch [" << name << "] => Output=" << (m_output ? 1 : 0) << std::endl;
}
