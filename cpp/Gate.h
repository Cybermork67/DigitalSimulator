#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>

class Gate {
protected:
    std::string name;
    std::vector<bool> inputs;
    std::vector<Gate*> wires;
    bool output = false;

public:
    Gate(std::string n, int numInputs = 2);
    virtual void setInput(int port, int val);
    bool getOutput() const;
    virtual bool evaluate() = 0;
    virtual void printState() const = 0;
    virtual ~Gate() {}
};
