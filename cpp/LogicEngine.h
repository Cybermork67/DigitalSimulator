#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Gate.h"

class LogicEngine {
private:
    std::string circuitName;
    int tickCount;
    std::vector<std::unique_ptr<Gate>> circuit;

public:
    LogicEngine();
    ~LogicEngine();
    void setCircuitName(std::string name);
    void addGate(std::unique_ptr<Gate> comp);
    void doTick();
    int getGateCount() const;
};
