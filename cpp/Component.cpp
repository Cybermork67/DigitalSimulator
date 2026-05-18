#include "Component.h"

Component::Component(std::string n) 
    : name(n), inA(false), inB(false), output(false) {
    std::cout << "[" << name << "] Komponente erstellt" << std::endl;
}

void Component::setInputA(int val) {
    if (val == 0) {
        inA = false;
    } else if (val == 1) {
        inA = true;
    } else {
        std::cerr << "[" << name << " FEHLER] Ungültiger Wert für Eingang A: " << val 
                  << " (erwartet 0 oder 1)" << std::endl;
    }
}

void Component::setInputB(int val) {
    if (val == 0) {
        inB = false;
    } else if (val == 1) {
        inB = true;
    } else {
        std::cerr << "[" << name << " FEHLER] Ungültiger Wert für Eingang B: " << val 
                  << " (erwartet 0 oder 1)" << std::endl;
    }
}

bool Component::getOutput() const {
    return output;
}
