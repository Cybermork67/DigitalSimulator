#include "Gate.h"

Gate::Gate(std::string n)
    : name(std::move(n)), m_output(false) {
    std::cout << "[" << name << "] Gate erstellt" << std::endl;
}

void Gate::connectInput(int port, Gate* source) {
    if (port < 0 || port >= static_cast<int>(m_inputs.size())) {
        std::cerr << "[" << name << " FEHLER] Ungültiger Port: " << port << std::endl;
        return;
    }
    m_inputs[port] = source;
}

bool Gate::getOutput() const {
    return m_output;
}
