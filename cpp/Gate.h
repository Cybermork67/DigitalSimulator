#pragma once

#include <string>
#include <iostream>

class Gate {
protected:
    std::string name;
    bool inA;
    bool inB;
    bool output;

public:
    Gate(std::string n);
    virtual void setInputA(int val);
    virtual void setInputB(int val);
    bool getOutput() const;
    virtual bool evaluate() = 0;
    virtual void printState() const = 0;
    virtual ~Gate() {}
};
