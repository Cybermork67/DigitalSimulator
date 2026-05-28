#pragma once

#include "Gate.h"

class OrGate : public Gate {
public:
    OrGate(std::string n);
    bool evaluate() override;
    void printState() const override;
};
