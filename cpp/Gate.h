#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>

class Gate {
protected:
    std::string name;
    std::vector<bool> m_inputs;
    std::vector<Gate*> wires;
    bool m_output = false;

public:
    Gate(std::string n);
    virtual void setInput(int port, int val);
    bool getOutput() const;
    virtual bool evaluate() = 0;
    virtual void printState() const = 0;
    virtual ~Gate() {}
};
