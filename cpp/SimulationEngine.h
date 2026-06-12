#include <vector>
#include <memory>
#include "Component.h"

class SimulationEngine {
private:

std::vector<std::shared_ptr<Gate>> m_gates;

public:

SimulationEngine() = default;

void addGate(std::shared_ptr<Gate> gate) {
  m_gates.push_back(gate); 
}

void resetAll() {
  for (auto gate : m_gates) {
    gate->reset();
  }
}

};