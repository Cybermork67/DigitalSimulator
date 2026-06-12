#include "LogicEngine.h"
#include "DFlipFlop.h"
#include <iostream>

LogicEngine::LogicEngine()
    : circuitName("Unbenannt"), tickCount(0) {
    std::cout << "[LogicEngine] Engine initialisiert" << std::endl;
}

void LogicEngine::setCircuitName(std::string name) {
    circuitName = name;
    std::cout << "[LogicEngine] Schaltungsname: " << circuitName << std::endl;
}

void LogicEngine::addComponent(std::unique_ptr<Gate> comp) {
    if (comp != nullptr) {
        circuit.push_back(std::move(comp));
    }
}

void LogicEngine::doTick() {
    tickCount++;

    // Phase A: Amnesie - Cache aller Gatter zuruecksetzen
    for (auto& c : circuit) {
        c->reset();
    }

    // Phase B: Lese-Phase - Kombinatorik berechnen
    for (auto& c : circuit) {
        c->evaluate();
    }

    // Phase C: Schreib-Phase - DFlipFlops per dynamic_cast finden und takten
    for (auto& c : circuit) {
        DFlipFlop* dff = dynamic_cast<DFlipFlop*>(c.get());
        if (dff != nullptr) {
            dff->onClockTick();
        }
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
}
