#pragma once

#include "Component.h"

class XorGate : public Component {
public:
    XorGate(std::string n);
    bool evaluate() override;
    void printState() const override;
};
