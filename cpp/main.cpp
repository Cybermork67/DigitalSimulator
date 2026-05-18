#include <iostream>
#include <memory>
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

    std::cout << "Baue Schaltung auf dem Heap..." << std::endl;

    auto g1 = std::make_unique<AndGate>("Haupt-AND");
    auto g2 = std::make_unique<OrGate>("Haupt-OR");
    auto g3 = std::make_unique<XorGate>("Test-XOR");

    std::cout << "\nSetze Signale..." << std::endl;
    g1->setInputA(1);
    g1->setInputB(1);

    g2->setInputA(0);
    g2->setInputB(1);

    g3->setInputA(1);
    g3->setInputB(0);

    engine.addComponent(std::move(g1));
    engine.addComponent(std::move(g2));
    engine.addComponent(std::move(g3));

    std::cout << "\nStarte Simulation:" << std::endl;
    engine.doTick();

    std::cout << "\nProgramm beendet. Speicher wird automatisch freigegeben." << std::endl;

    return 0;
}
