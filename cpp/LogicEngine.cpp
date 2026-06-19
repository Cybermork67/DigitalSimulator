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

Gate* LogicEngine::getGateByName(const std::string& name) {
    for (auto& comp : circuit) {
        if (comp->getName() == name) {
            return comp.get(); //gibt raw Pointer zurück
        }
    }
    // nicht gefunden
    std:cerr << "[LogicEngine] Fehler: Gatter " << name << " nicht gefunden!" << std::endl;
    return nullptr;
}

void LogicEngine::loadFromFile(const std::string& filename) {
    std::cerr << "\n[LogicEngine] Lade Schaltung aus Datei: " << filename << std::endl;

    std:ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "[LogicEngine ERROR] Kann Datei nicht öffnen: " << filename << std::endl;
        return;
    }

    std::string line;
    int lineNumber = 0;
    int gateCount = 0, wireCount = 0;

    while (std::getline(file, line)) {
        lineNumber++;

        //Ingoriere leere Zeilen
        if (line.empty()) continue;

        //Ignoriere Kommentare (Zeilen die mit # oder // beginnen)
        if (line[0] == '#' || (line.length() > 1 && line[0] == '/' && line[1] == '/')) {
            continue;
        }

        // Parse Zeile mit stringstream
        std::istringstream ss(line);
        std::string command; //Erstes Wort extrahieren 

        //GATE Zeilen
        if (command == "Gate") {
            std::string type, name;
            ss >> type >> name;

            if (type.empty() || name.empty()) {
                std::cerr << "[LogicEngine WARNING] Zeile " << lineNumber << ": GATE Format ungültig" << std::endl;
                continue;
            }
        }
    }