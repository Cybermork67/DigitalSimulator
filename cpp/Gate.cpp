#include "Gate.h"

Gate::Gate(std::string n) 
    : name(std::move(n)), inA(false), inB(false), output(false) {
    std::cout << "[" << name << "] Gate erstellt" << std::endl;
}

void Gate::setInput(int port, int val) {
    bool bval;
    if (val == 0)       bval = false;
    else if (val == 1)  bval = true;
    else {
        std::cerr << "[" << name << " FEHLER] Ungültiger Wert: " << val
                  << " (erwartet 0 oder 1)" << std::endl;
        return;
    }
    if (port == 0)      inA = bval;
    else if (port == 1) inB = bval;
    else {
        std::cerr << "[" << name << " FEHLER] Ungültiger Port: " << port
                  << " (erwartet 0 oder 1)" << std::endl;
    }
}

bool Gate::getOutput() const {
    return output;
}
