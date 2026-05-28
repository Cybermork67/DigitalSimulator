#pragma once

#include "Gate.h"

class NandGate : public Gate {
public:
    NandGate(std::string n);
    bool evaluate() override;
    void printState() const override;
};
