#pragma once

#include "Gate.h"

class NotGate : public Gate {
public:
    NotGate(std::string n);
    void setInputB(int val) override;
    bool evaluate() override;
    void printState() const override;
};
