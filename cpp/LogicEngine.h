#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Component.h"

class LogicEngine {
private:
    std::string circuitName;
    int tickCount = 0;
    std::vector<std::shared_ptr<Gate>> circuit;

public:
    LogicEngine();
    ~LogicEngine() = default;

    void setCircuitName(std::string name);
    void addComponent(std::shared_ptr<Gate> comp);
    void reserveComponents(int expectedCount);
    void doTick();
    int getComponentCount() const;
};
