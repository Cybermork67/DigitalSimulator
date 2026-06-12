#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Component.h"

class LogicEngine {
private:
    std::string circuitName;
    int tickCount = 0;
    std::vector<std::unique_ptr<Gate>> circuit;

public:
    LogicEngine();
    ~LogicEngine() = default;

    void setCircuitName(std::string name);
    void addComponent(std::unique_ptr<Gate> comp);
    void reserveComponents(int expectedCount);

    // Fuehrt den vollen 2-Phasen-Taktzyklus aus:
    // Phase A: reset(), Phase B: evaluate(), Phase C: onClockTick() via dynamic_cast
    void doTick();

    int getComponentCount() const;
};
