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
    std::vector<std::shared_ptr<Gate>> m_inputs;

public:
    Gate(std::string n);

    void connectInput(int index, std::shared_ptr<Gate> source);
    bool getOutput() const;

    // Cache zuruecksetzen (Phase A der 2-Phasen-Schleife)
    void reset();

    virtual void evaluate() = 0;
    virtual void printState() const = 0;
    virtual ~Gate();
};
