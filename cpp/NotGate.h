#pragma once

#include "Component.h"

class NotGate : public Component {
public:
    NotGate(std::string n);
    void setInputB(int val) override;
    bool evaluate() override;
    void printState() const override;
};
