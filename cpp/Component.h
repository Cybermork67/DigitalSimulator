#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <memory>

class Gate {
protected:
    bool m_isCalculated = false;
    std::string m_name;
    bool m_output = false;
    std::vector<Gate*> m_inputs; // Rohe Zeiger: Ownership liegt bei der Engine

public:
    Gate(std::string n);

    // Verbindet einen Eingang mit einem anderen Gatter (kein Ownership-Transfer)
    void connectInput(int index, Gate* source);

    bool getOutput() const;

    // Cache-Reset fuer Phase A der 2-Phasen-Schleife
    void reset();

    virtual void evaluate() = 0;
    virtual void printState() const = 0;
    virtual ~Gate();
};
