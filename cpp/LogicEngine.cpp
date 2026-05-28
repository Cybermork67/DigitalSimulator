#include "LogicEngine.h"
#include <iostream>

LogicEngine::LogicEngine() 
    : circuitName("Unbenannt"), tickCount(0) {
    std::cout << "[LogicEngine] Engine initialisiert" << std::endl;
}

LogicEngine::~LogicEngine() {
    circuit.clear();
}

void LogicEngine::setCircuitName(std::string name) {
    circuitName = name;
    std::cout << "[LogicEngine] Schaltungsname gesetzt: " << circuitName << std::endl;
}

void LogicEngine::addGate(std::unique_ptr<Gate> comp) {
    if (comp != nullptr) {
        circuit.push_back(std::move(comp));
        std::cout << "[LogicEngine] Gate hinzugefügt. Gesamt: " << circuit.size() << std::endl;
    }
}

void LogicEngine::doTick() {
    tickCount++;
    std::cout << "\n[Tick " << tickCount << "] Evaluiere " << circuit.size() 
              << " Gates:" << std::endl;
    
    for (auto& c : circuit) {
        bool result = c->evaluate();
        std::cout << "  => Ergebnis: " << (result ? "true" : "false") << std::endl;
    }
}

int LogicEngine::getGateCount() const {
    return circuit.size();
}
