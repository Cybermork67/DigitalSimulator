#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Component.h"


class LogicEngine {
private:
    std::string circuitName;
    int tickCount;
    std::vector<std::unique_ptr<Component>> circuit;

public:
    LogicEngine();
    ~LogicEngine();
    void setCircuitName(std::string name);
    void addComponent(std::unique_ptr<Component> comp);
    void doTick();
    int getComponentCount() const;
};
