#include <iostream>
#include <memory>
#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"
#include "XorGate.h"
#include "NandGate.h"

int main() {
    bool testPassed = true;

    std::cout << "--- STARTE AUTOMATISIERTE WAHRHEITSTABELLEN-TESTS ---" << std::endl;

    // AND-Gatter: 4 Testfaelle (0-0->0, 0-1->0, 1-0->0, 1-1->1)
    {
        auto gate = std::make_unique<AndGate>("AND-Test");
        int tests[4][3] = {{0,0,0},{0,1,0},{1,0,0},{1,1,1}};
        for (int i = 0; i < 4; ++i) {
            gate->setInputA(tests[i][0]);
            gate->setInputB(tests[i][1]);
            int result = gate->evaluate() ? 1 : 0;
            if (result != tests[i][2]) {
                std::cerr << "FEHLER AND: A=" << tests[i][0] << " B=" << tests[i][1]
                          << " -> Erhalten: " << result
                          << " (Erwartet: " << tests[i][2] << ")" << std::endl;
                testPassed = false;
            }
        }
    }

    // OR-Gatter: 4 Testfaelle (0-0->0, 0-1->1, 1-0->1, 1-1->1)
    {
        auto gate = std::make_unique<OrGate>("OR-Test");
        int tests[4][3] = {{0,0,0},{0,1,1},{1,0,1},{1,1,1}};
        for (int i = 0; i < 4; ++i) {
            gate->setInputA(tests[i][0]);
            gate->setInputB(tests[i][1]);
            int result = gate->evaluate() ? 1 : 0;
            if (result != tests[i][2]) {
                std::cerr << "FEHLER OR: A=" << tests[i][0] << " B=" << tests[i][1]
                          << " -> Erhalten: " << result
                          << " (Erwartet: " << tests[i][2] << ")" << std::endl;
                testPassed = false;
            }
        }
    }

    // XOR-Gatter: 4 Testfaelle (0-0->0, 0-1->1, 1-0->1, 1-1->0)
    {
        auto gate = std::make_unique<XorGate>("XOR-Test");
        int tests[4][3] = {{0,0,0},{0,1,1},{1,0,1},{1,1,0}};
        for (int i = 0; i < 4; ++i) {
            gate->setInputA(tests[i][0]);
            gate->setInputB(tests[i][1]);
            int result = gate->evaluate() ? 1 : 0;
            if (result != tests[i][2]) {
                std::cerr << "FEHLER XOR: A=" << tests[i][0] << " B=" << tests[i][1]
                          << " -> Erhalten: " << result
                          << " (Erwartet: " << tests[i][2] << ")" << std::endl;
                testPassed = false;
            }
        }
    }

    // NAND-Gatter: 4 Testfaelle (0-0->1, 0-1->1, 1-0->1, 1-1->0)
    {
        auto gate = std::make_unique<NandGate>("NAND-Test");
        int tests[4][3] = {{0,0,1},{0,1,1},{1,0,1},{1,1,0}};
        for (int i = 0; i < 4; ++i) {
            gate->setInputA(tests[i][0]);
            gate->setInputB(tests[i][1]);
            int result = gate->evaluate() ? 1 : 0;
            if (result != tests[i][2]) {
                std::cerr << "FEHLER NAND: A=" << tests[i][0] << " B=" << tests[i][1]
                          << " -> Erhalten: " << result
                          << " (Erwartet: " << tests[i][2] << ")" << std::endl;
                testPassed = false;
            }
        }
    }

    // NOT-Gatter: 2 Testfaelle (0->1, 1->0)
    {
        auto gate = std::make_unique<NotGate>("NOT-Test");
        int tests[2][2] = {{0,1},{1,0}};
        for (int i = 0; i < 2; ++i) {
            gate->setInputA(tests[i][0]);
            int result = gate->evaluate() ? 1 : 0;
            if (result != tests[i][1]) {
                std::cerr << "FEHLER NOT: A=" << tests[i][0]
                          << " -> Erhalten: " << result
                          << " (Erwartet: " << tests[i][1] << ")" << std::endl;
                testPassed = false;
            }
        }
    }

    if (!testPassed) {
        std::cerr << "--- PIPELINE-ABSTURZ: TESTS FEHLGESCHLAGEN ---" << std::endl;
        return 1;
    }

    std::cout << "--- ALLE TESTS BESTANDEN (18/18) ---" << std::endl;
    return 0;
}
