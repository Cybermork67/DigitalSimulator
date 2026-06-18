#include <iostream>
#include <memory>
#include "LogicEngine.h"
#include "Switch.h"
#include "DFlipFlop.h"

// Phase 3: ASCII-Timing-Diagramm ausgeben
// '_' = Low (0),  ¯ = High (1)
void printWaveform(int tick, bool val0, bool val1, bool val2, bool val3) {
    auto sym = [](bool v) -> const char* { return v ? "\xC2\xAF" : "_"; };
    std::cout << "Tick " << tick << " | "
              << sym(val0) << " "
              << sym(val1) << " "
              << sym(val2) << " "
              << sym(val3) << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  C++ Digital Simulator - Labor 11" << std::endl;
    std::cout << "  4-Bit Schieberegister" << std::endl;
    std::cout << "========================================\n" << std::endl;

    LogicEngine engine;
    engine.setCircuitName("Schieberegister");

    // Phase 2: Bauteile erzeugen
    auto swIn = std::make_unique<Switch>("DataIn");
    auto d0   = std::make_unique<DFlipFlop>("d0");
    auto d1   = std::make_unique<DFlipFlop>("d1");
    auto d2   = std::make_unique<DFlipFlop>("d2");
    auto d3   = std::make_unique<DFlipFlop>("d3");

    // Rohe Zeiger vor dem move sichern
    Switch*    swPtr = swIn.get();
    DFlipFlop* d0Ptr = d0.get();
    DFlipFlop* d1Ptr = d1.get();
    DFlipFlop* d2Ptr = d2.get();
    DFlipFlop* d3Ptr = d3.get();

    // Serielle Verkabelung: DataIn -> d0 -> d1 -> d2 -> d3
    d0->connectInput(0, swPtr);
    d1->connectInput(0, d0Ptr);
    d2->connectInput(0, d1Ptr);
    d3->connectInput(0, d2Ptr);

    // Ownership an Engine uebertragen
    engine.addComponent(std::move(swIn));
    engine.addComponent(std::move(d0));
    engine.addComponent(std::move(d1));
    engine.addComponent(std::move(d2));
    engine.addComponent(std::move(d3));

    std::cout << "\n[INFO] Schaltkreis hat "
              << engine.getComponentCount() << " Komponenten.\n" << std::endl;

    std::cout << "Legende: _ = 0 (Low)   \xC2\xAF = 1 (High)" << std::endl;
    std::cout << "         d0 d1 d2 d3" << std::endl;
    std::cout << "----------------------------" << std::endl;

    // Tick 1: DataIn = 1
    swPtr->setState(true);
    engine.doTick();
    printWaveform(1, d0Ptr->getOutput(), d1Ptr->getOutput(),
                     d2Ptr->getOutput(), d3Ptr->getOutput());

    // Ticks 2-5: DataIn = 0, '1' wandert durch das Register
    swPtr->setState(false);
    for (int t = 2; t <= 5; ++t) {
        engine.doTick();
        printWaveform(t, d0Ptr->getOutput(), d1Ptr->getOutput(),
                         d2Ptr->getOutput(), d3Ptr->getOutput());
    }

    std::cout << "----------------------------" << std::endl;
    std::cout << "\n[SUCCESS] Die '1' ist durch alle 4 Flip-Flops gewandert!" << std::endl;

    return 0;
}
