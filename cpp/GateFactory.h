#pragma once

#include <string>
#include <memory>
#include "Component.h"

class GateFactory {
public:
  static std::unique_ptr<Gate> createGate(const std::string& type, 
                                          const std::string& name);
};