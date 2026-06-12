#include "Component.h"

Gate::Gate(std::string n)
    : m_name(n), m_output(false) {
    std::cout << "[" << m_name << "] Gate erstellt" << std::endl;
}

void Gate::connectInput(int index, std::shared_ptr<Gate> source) {
    if (index >= 0 && index < static_cast<int>(m_inputs.size())) {
        m_inputs[index] = source;
        std::cout << "[VERKABELUNG] " << m_name << " Pin " << index
                  << " verbunden mit " << source->m_name << std::endl;
    } else {
        std::cerr << "[FEHLER] " << m_name << ": Pin " << index
                  << " existiert nicht! (Verfügbar: 0-"
                  << (m_inputs.size() - 1) << ")" << std::endl;
    }
}

bool Gate::getOutput() const {
    return m_output;
}

void Gate::reset() {
    m_isCalculated = false;
}

Gate::~Gate() {
    std::cout << "[DESTRUKTOR] " << m_name << std::endl;
}
