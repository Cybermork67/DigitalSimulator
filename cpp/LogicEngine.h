#pragma once

#include <string>
#include <vector>
#include "Component.h"

class LogicEngine {
private:
    std::string circuitName;
    int tickCount;
    std::vector<Component*> circuit;

public:
    LogicEngine();
    ~LogicEngine();
    void setCircuitName(std::string name);
    void addComponent(Component* comp);
    void doTick();
    int getComponentCount() const;
};
