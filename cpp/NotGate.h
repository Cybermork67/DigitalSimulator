#pragma once

#include "Gate.h"

class NotGate : public Gate {
public:
    NotGate(std::string n);
    void connectInput(int port, Gate* source) override;
    bool evaluate() override;
    void printState() const override;
};
