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

    Component* g1 = new AndGate("Haupt-AND");
    Component* g2 = new OrGate("Haupt-OR");
    Component* g3 = new XorGate("Test-XOR");

    engine.addComponent(g1);
    engine.addComponent(g2);
    engine.addComponent(g3);

    std::cout << "\nSetze Signale..." << std::endl;
    g1->setInputA(1);
    g1->setInputB(1);
    
    g2->setInputA(0);
    g2->setInputB(1);
    
    g3->setInputA(1);
    g3->setInputB(0);

    std::cout << "\nStarte Simulation:" << std::endl;
    engine.doTick();

    std::cout << "\nProgramm beendet. Achtung: RAM wurde nicht freigegeben!" << std::endl;

    return 0;
}
