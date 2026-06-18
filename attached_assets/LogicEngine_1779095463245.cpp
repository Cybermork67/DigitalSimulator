#include "LogicEngine.h"
#include <iostream>

// ============================================
// LogicEngine Implementation
// ============================================

/**
 * Konstruktor: Initialisiert die Engine
 */
LogicEngine::LogicEngine() 
    : circuitName("Unbenannt"), tickCount(0) {
    std::cout << "[LogicEngine] Engine initialisiert" << std::endl;
}

/**
 * Destruktor: Gibt dynamisch allokierte Komponenten frei
 * WICHTIG: Nur der Zeiger wird gelöscht, nicht die Objekte selbst
 * (diese sollten vom Aufrufer verwaltet werden, oder wir geben Ownership ab)
 */
LogicEngine::~LogicEngine() {
    // Wir löschen hier NICHT die Komponenten, da sie möglicherweise 
    // von außerhalb verwaltet werden (Stack-Allokation)
    // Nur wenn wir mit new allokieren würden, müssten wir hier delete aufrufen
    circuit.clear();
}

/**
 * Setzt den Namen der Schaltung
 */
void LogicEngine::setCircuitName(std::string name) {
    circuitName = name;
    std::cout << "[LogicEngine] Schaltungsname gesetzt: " << circuitName << std::endl;
}

/**
 * Fügt eine Komponente zur Schaltung hinzu
 * Dies ist der Schlüssel zu Polymorphismus:
 * Wir speichern einen Component*-Zeiger, wissen aber nicht, was dahinter steckt
 */
void LogicEngine::addComponent(Component* comp) {
    if (comp != nullptr) {
        circuit.push_back(comp);
        std::cout << "[LogicEngine] Komponente hinzugefügt. Gesamt: " << circuit.size() << std::endl;
    }
}

/**
 * doTick(): Der Kern der Simulation!
 * 
 * Dies ist der erste praktische Beispiel für Polymorphismus:
 * Wir wissen nicht, welchen konkreten Typ jede Komponente hat,
 * aber der Compiler generiert automatisch die richtigen virtuellen Aufrufe!
 */
void LogicEngine::doTick() {
    tickCount++;
    std::cout << "\n[Tick " << tickCount << "] Evaluiere " << circuit.size() 
              << " Komponenten:" << std::endl;
    
    for (Component* c : circuit) {
        // Polymorphe Funktion: Der Compiler findet automatisch die richtige evaluate()-Methode!
        bool result = c->evaluate();
        std::cout << "  => Ergebnis: " << (result ? "true" : "false") << std::endl;
    }
}

/**
 * Gibt die Anzahl der Komponenten zurück
 */
int LogicEngine::getComponentCount() const {
    return circuit.size();
}