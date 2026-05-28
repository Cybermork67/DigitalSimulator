#pragma once

#include "Gate.h"

class XorGate : public Gate {
public:
    XorGate(std::string n);
    bool evaluate() override;
    void printState() const override;
};
