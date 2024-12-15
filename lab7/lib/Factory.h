#pragma once
#include <memory>
#include "Npc.h"
#include <stdexcept>

class AbstractFactory {
public:
    virtual std::unique_ptr<Npc> create_npc() = 0;
    virtual ~AbstractFactory() = default;
};

class Factory: public AbstractFactory {
public:
    static std::shared_ptr<Npc> create_npc(const std::string& type, const std::string& name, double x, double y) {
        if (type == "Knight") {
            return std::make_shared<Knight>(name, x, y);
        }
        else if (type == "Dragon") {
            return std::make_shared<Dragon>(name, x, y);
        }
        else if (type == "Pegas") {
            return std::make_shared<Pegas>(name, x, y);
        }
        else {
            throw std::invalid_argument("Unknown NPC type: " + type);
        }
    }
};