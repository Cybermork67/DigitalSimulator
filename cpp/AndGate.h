#pragma once

#include "Gate.h"

class AndGate : public Gate {
public:
    AndGate(std::string n);
    bool evaluate() override final;
    void printState() const override;
};
