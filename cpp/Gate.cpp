#include "Gate.h"

Gate::Gate(std::string n, int numInputs)
    : name(std::move(n)), inputs(numInputs, false), output(false) {
    std::cout << "[" << name << "] Gate erstellt" << std::endl;
}

void Gate::setInput(int port, int val) {
    if (port < 0 || port >= static_cast<int>(inputs.size())) {
        std::cerr << "[" << name << " FEHLER] Ungültiger Port: " << port << std::endl;
        return;
    }
    if (val == 0)      inputs[port] = false;
    else if (val == 1) inputs[port] = true;
    else {
        std::cerr << "[" << name << " FEHLER] Ungültiger Wert: " << val
                  << " (erwartet 0 oder 1)" << std::endl;
    }
}

bool Gate::getOutput() const {
    return output;
}
