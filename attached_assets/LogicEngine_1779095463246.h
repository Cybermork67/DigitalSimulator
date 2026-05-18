#pragma once

#include <string>
#include <vector>
#include "Component.h"

/**
 * Die LogicEngine ist der Kern unseres Simulators.
 * Sie verwaltet eine Liste von Komponenten polymorphisch.
 * 
 * Das Schlüsselkonzept: Wir speichern Zeiger auf die Basisklasse Component,
 * aber die Engine "weiß" nicht, welcher konkrete Typ verborgen ist.
 * Durch polymorphe Aufrufe werden die richtigen Gatter-Logiken ausgeführt!
 */
class LogicEngine {
private:
    std::string circuitName;
    int tickCount;
    std::vector<Component*> circuit;  // Polymorphe Liste von Komponenten

public:
    // Konstruktor: Initialisiert die Engine
    LogicEngine();

    // Destruktor: Räumt die Komponenten auf
    ~LogicEngine();

    // Setzt den Namen der Schaltung
    void setCircuitName(std::string name);

    // Fügt eine Komponente polymorphisch zur Schaltung hinzu
    void addComponent(Component* comp);

    // Berechnet einen Taktschritt: Evaluiert alle Komponenten
    void doTick();

    // Gibt die Anzahl der Komponenten zurück
    int getComponentCount() const;
};