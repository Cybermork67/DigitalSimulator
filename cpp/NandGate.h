#pragma once

#include "Component.h"
#include "AndGate.h"
#include "NotGate.h"

class NandGate : public Component {
private:
    AndGate andGate;
    NotGate notGate;

public:
    NandGate(std::string n);
    void setInputA(int val) override;
    void setInputB(int val) override;
    bool evaluate() override;
    void printState() const override;
};
