#pragma once

#include "Component.h"

class AndGate : public Component {
public:
    AndGate(std::string n);
    bool evaluate() override final;
    void printState() const override;
};
