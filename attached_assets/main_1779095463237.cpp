#include <iostream>
#include <vector>
#include "Component.h"
#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"
#include "XorGate.h"
#include "NandGate.h"
#include "LogicEngine.h"

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Labor 5: Speichersicherheit & Refactoring" << std::endl;
    std::cout << "Ausgangslage: Rohe Pointer und Memory Leaks" << std::endl;
    std::cout << "========================================\n" << std::endl;

    LogicEngine engine;
    engine.setCircuitName("Leak-Test-Schaltung");

    std::cout << "Baue Schaltung auf dem Heap (Wird aktuell NICHT gelöscht!)..." << std::endl;

    // ---------------------------------------------------------
    // VERALTETER CODE: Nutzung von nacktem 'new'.
    // Dieser Code erzeugt absichtlich ein Memory Leak, da das 
    // zugehörige 'delete' nirgends aufgerufen wird!
    // ---------------------------------------------------------
    Component* g1 = new AndGate("Haupt-AND");
    Component* g2 = new OrGate("Haupt-OR");
    Component* g3 = new XorGate("Test-XOR");

    // Gatter an die Engine übergeben (erwartet aktuell Component*)
    engine.addComponent(g1);
    engine.addComponent(g2);
    engine.addComponent(g3);

    // Test-Eingänge setzen
    std::cout << "\nSetze Signale..." << std::endl;
    g1->setInputA(1);
    g1->setInputB(1);
    
    g2->setInputA(0);
    g2->setInputB(1);
    
    g3->setInputA(1);
    g3->setInputB(0);

    // Simulation einmal durchrechnen
    std::cout << "\nStarte Simulation:" << std::endl;
    engine.doTick();

    std::cout << "\nProgramm beendet. Achtung: RAM wurde nicht freigegeben!" << std::endl;

    // FEHLER: Hier fehlen 'delete g1;', 'delete g2;', 'delete g3;'
    
    return 0;
}