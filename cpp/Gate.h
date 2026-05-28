#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>

class Gate {
protected:
    std::string name;
    std::vector<Gate*> m_inputs; // Pull-Prinzip: Zeiger auf verbundene Vorgänger-Gates
    bool m_output = false;

public:
    Gate(std::string n);
    virtual void connectInput(int port, Gate* source);
    bool getOutput() const;
    virtual bool evaluate() = 0;
    virtual void printState() const = 0;
    virtual ~Gate() {}
};
