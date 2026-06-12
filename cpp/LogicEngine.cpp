#include "LogicEngine.h"
#include <iostream>

LogicEngine::LogicEngine()
    : circuitName("Unbenannt"), tickCount(0) {
    std::cout << "[LogicEngine] Engine initialisiert" << std::endl;
}

void LogicEngine::setCircuitName(std::string name) {
    circuitName = name;
    std::cout << "[LogicEngine] Schaltungsname: " << circuitName << std::endl;
}

void LogicEngine::addComponent(std::shared_ptr<Gate> comp) {
    if (comp != nullptr) {
        circuit.push_back(comp);
        std::cout << "[LogicEngine] Komponente hinzugefügt. Gesamt: "
                  << circuit.size() << std::endl;
    }
}

void LogicEngine::doTick() {
    tickCount++;
    std::cout << "\n[Tick " << tickCount << "] Evaluiere "
              << circuit.size() << " Komponenten:" << std::endl;
    for (auto& c : circuit) {
        c->reset();
    }
    for (auto& c : circuit) {
        c->evaluate();
        std::cout << "  => " << (c->getOutput() ? "true" : "false") << std::endl;
    }
}

int LogicEngine::getComponentCount() const {
    return static_cast<int>(circuit.size());
}

void LogicEngine::reserveComponents(int expectedCount) {
    if (expectedCount <= 0) {
        std::cerr << "[LogicEngine] Warnung: expectedCount muss > 0 sein!" << std::endl;
        return;
    }
    circuit.reserve(static_cast<size_t>(expectedCount));
    std::cout << "[LogicEngine] Speicher reserviert für " << expectedCount
              << " Komponenten. Kapazität: " << circuit.capacity()
              << " (size: " << circuit.size() << ")" << std::endl;
}
