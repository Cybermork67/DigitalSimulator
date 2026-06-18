#pragma once

#include "Component.h"

class NotGate : public Gate {
public:
    NotGate(std::string n);
    void evaluate() override;
    void printState() const override;
};
