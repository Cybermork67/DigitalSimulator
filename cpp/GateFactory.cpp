#include "Component.h"
#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"
#include "NandGate.h"
#include "XorGate.h"
#include "Switch.h"
#include "DFlipFlopEnable.h"
#include "DFlipFlop.h"
#include "GateFactory.h"

#include <iostream>

static std::unique_ptr<Gate> GateFactory::createGate(const std::string& type, const std::string& name);

// Kombinatorische Gatter 

if(type == "AND") {
    std::cout << "[GateFactory] Erstelle AND-Gatter: " << name << std::endl;
    return std::make_unique<AndGate>(name);
}

else if (type == "OR") {
    std::cout << "[GateFactory] Erstelle OR-Gatter: " << name << std::endl;
    return std::make_unique<OrGate>(name);
}

else  if (type == "NOT") {
    std::cout << "[GateFactory] Erstelle NOT-Gatter: " << name << std::endl;
    return std::make_unique<NotGate>(name);
}

else if (type == "NAND") {
    std::cout << "[GateFactory] Erstelle NAND-Gatter: " << name << std::endl;
    return std::make_unique<NandGate>(name);
}

else if (type == "XOR") {
    std::cout << "[GateFactory] Erstelle XOR-Gatter: " << name << std::endl;
    return std::make_unique<XorGate>(name); 
}

//Datenquellen und Speicher 
else if (type == "SWITCH") {
    std::cout << "[GateFactory] Erstelle Schalter: " << name << std::endl;
    return std::make_unique<Switch>(name);
}

else if (type == "DFF") {
    std::cout << "[GateFactory] Erstelle D-FlipFlop: " << name << std::endl;
    return std::make_unique<DFlipFlop>(name);
}

else if (type == "DFFE") {
    std::cout << "[GateFactory] Erstelle D-FlipFlop mit Enable: " << name << std::endl;
    return std::make_unique<DFlipFlopEnable>(name);
}

//Fehlerbehandlung: Unbekannter Typ
else {
    std::cerr << "[GateFactory] Unbekannter Gattertyp: " << type << std::endl;
    return nullptr;
}
