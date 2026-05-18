#pragma once

#include "Component.h"

class OrGate : public Component {
public:
    OrGate(std::string n);
    bool evaluate() override;
    void printState() const override;
};
