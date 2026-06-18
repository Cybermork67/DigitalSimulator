#pragma once

#include "Component.h"

class Switch : public Gate {
public:
    Switch(std::string n);
    void setState(bool state);
    void evaluate() override;
    void printState() const override;
};
