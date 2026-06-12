#pragma once

#include "Component.h"

class AndGate : public Gate {
public:
    AndGate(std::string n);
    void evaluate() override;
    void printState() const override;
};
