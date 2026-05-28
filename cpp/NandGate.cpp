#include "NandGate.h"
#include <iostream>

NandGate::NandGate(std::string n) 
    : Gate(n), andGate(n + "-AND"), notGate(n + "-NOT") {
    std::cout << "[" << name << "] NAND-Gatter aktiviert (Komposition: AND + NOT)" << std::endl;
}

void NandGate::setInputA(int val) {
    inA = (val != 0);
    andGate.setInputA(val);
}

void NandGate::setInputB(int val) {
    inB = (val != 0);
    andGate.setInputB(val);
}

bool NandGate::evaluate() {
    bool andResult = andGate.evaluate();
    notGate.setInputA(andResult ? 1 : 0);
    output = notGate.evaluate();
    return output;
}

void NandGate::printState() const {
    std::cout << "NandGate [" << name << ": A=" << (inA ? 1 : 0) 
              << ", B=" << (inB ? 1 : 0) 
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}
