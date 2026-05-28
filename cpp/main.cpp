#include <iostream>
#include <memory>
#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"
#include "XorGate.h"
#include "NandGate.h"

// Hilfklasse: konstante Signalquelle fuer Tests (kein echtes Gate)
class SignalSource : public Gate {
    bool m_value;
public:
    SignalSource(std::string n, bool val) : Gate(n), m_value(val) {
        m_output = val;
    }
    void setValue(bool val) { m_value = val; m_output = val; }
    bool evaluate() override { m_output = m_value; return m_output; }
    void printState() const override {}
};

int main() {
    bool testPassed = true;

    std::cout << "--- STARTE AUTOMATISIERTE WAHRHEITSTABELLEN-TESTS ---" << std::endl;

    // AND-Gatter: 4 Testfaelle
    {
        AndGate gate("AND-Test");
        SignalSource srcA("A", false), srcB("B", false);
        gate.connectInput(0, &srcA);
        gate.connectInput(1, &srcB);
        int tests[4][3] = {{0,0,0},{0,1,0},{1,0,0},{1,1,1}};
        for (int i = 0; i < 4; ++i) {
            srcA.setValue(tests[i][0]); srcB.setValue(tests[i][1]);
            int result = gate.evaluate() ? 1 : 0;
            if (result != tests[i][2]) {
                std::cerr << "FEHLER AND: A=" << tests[i][0] << " B=" << tests[i][1]
                          << " -> Erhalten: " << result
                          << " (Erwartet: " << tests[i][2] << ")" << std::endl;
                testPassed = false;
            }
        }
    }

    // OR-Gatter: 4 Testfaelle
    {
        OrGate gate("OR-Test");
        SignalSource srcA("A", false), srcB("B", false);
        gate.connectInput(0, &srcA);
        gate.connectInput(1, &srcB);
        int tests[4][3] = {{0,0,0},{0,1,1},{1,0,1},{1,1,1}};
        for (int i = 0; i < 4; ++i) {
            srcA.setValue(tests[i][0]); srcB.setValue(tests[i][1]);
            int result = gate.evaluate() ? 1 : 0;
            if (result != tests[i][2]) {
                std::cerr << "FEHLER OR: A=" << tests[i][0] << " B=" << tests[i][1]
                          << " -> Erhalten: " << result
                          << " (Erwartet: " << tests[i][2] << ")" << std::endl;
                testPassed = false;
            }
        }
    }

    // XOR-Gatter: 4 Testfaelle
    {
        XorGate gate("XOR-Test");
        SignalSource srcA("A", false), srcB("B", false);
        gate.connectInput(0, &srcA);
        gate.connectInput(1, &srcB);
        int tests[4][3] = {{0,0,0},{0,1,1},{1,0,1},{1,1,0}};
        for (int i = 0; i < 4; ++i) {
            srcA.setValue(tests[i][0]); srcB.setValue(tests[i][1]);
            int result = gate.evaluate() ? 1 : 0;
            if (result != tests[i][2]) {
                std::cerr << "FEHLER XOR: A=" << tests[i][0] << " B=" << tests[i][1]
                          << " -> Erhalten: " << result
                          << " (Erwartet: " << tests[i][2] << ")" << std::endl;
                testPassed = false;
            }
        }
    }

    // NAND-Gatter: 4 Testfaelle
    {
        NandGate gate("NAND-Test");
        SignalSource srcA("A", false), srcB("B", false);
        gate.connectInput(0, &srcA);
        gate.connectInput(1, &srcB);
        int tests[4][3] = {{0,0,1},{0,1,1},{1,0,1},{1,1,0}};
        for (int i = 0; i < 4; ++i) {
            srcA.setValue(tests[i][0]); srcB.setValue(tests[i][1]);
            int result = gate.evaluate() ? 1 : 0;
            if (result != tests[i][2]) {
                std::cerr << "FEHLER NAND: A=" << tests[i][0] << " B=" << tests[i][1]
                          << " -> Erhalten: " << result
                          << " (Erwartet: " << tests[i][2] << ")" << std::endl;
                testPassed = false;
            }
        }
    }

    // NOT-Gatter: 2 Testfaelle
    {
        NotGate gate("NOT-Test");
        SignalSource src("A", false);
        gate.connectInput(0, &src);
        int tests[2][2] = {{0,1},{1,0}};
        for (int i = 0; i < 2; ++i) {
            src.setValue(tests[i][0]);
            int result = gate.evaluate() ? 1 : 0;
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
