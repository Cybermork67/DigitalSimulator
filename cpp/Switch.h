#pragma once

#include "Gate.h"

class Switch : public Gate {
public:
    Switch(std::string n);
    void connectInput(int port, Gate* source) override;
    void setState(bool state);
    bool evaluate() override;
    void printState() const override;
};
