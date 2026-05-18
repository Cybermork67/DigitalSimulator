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

void LogicEngine::addComponent(std::unique_ptr<Component> c) {
    if (c != nullptr) {
        circuit.push_back(std::move(c));
        std::cout << "[LogicEngine] Komponente hinzugefügt. Gesamt: " << circuit.size() << std::endl;
    }
}

void LogicEngine::doTick() {
    tickCount++;
    std::cout << "\n[Tick " << tickCount << "] Evaluiere " << circuit.size() 
              << " Komponenten:" << std::endl;
    
    for (const auto& c : circuit) {
        bool result = c->evaluate();
        std::cout << "  => Ergebnis: " << (result ? "true" : "false") << std::endl;
    }
}

int LogicEngine::getComponentCount() const {
    return circuit.size();
}
