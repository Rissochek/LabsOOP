#include "NPC.h"

// Реализация конструктора NPC
NPC::NPC(Coordinates cords, std::string name) : npc_coords(cords), name(name) {}

// Реализация метода get_name
std::string NPC::get_name() const {
    return name;
}

// Реализация метода get_coords
Coordinates NPC::get_coords() const {
    return this->npc_coords;
}

// Реализация конструктора Knight
Knight::Knight(Coordinates cords, std::string name) : NPC(cords, name) {}

// Реализация метода get_type для Knight
std::string Knight::get_type() const {
    return "Knight";
}

// Реализация метода addObserver для Knight
void Knight::addObserver(std::shared_ptr<AbstractObserver> observer) {
    observers.push_back(observer);
}

// Реализация метода notifyObservers для Knight
void Knight::notifyObservers(const std::string& loser) {
    for (auto& observer : observers) {
        observer->update(this->name, loser);
    }
}

// Реализация конструктора Pegas
Pegas::Pegas(Coordinates cords, std::string name) : NPC(cords, name) {}

// Реализация метода get_type для Pegas
std::string Pegas::get_type() const {
    return "Pegas";
}

// Реализация метода addObserver для Pegas
void Pegas::addObserver(std::shared_ptr<AbstractObserver> observer) {
    observers.push_back(observer);
}

// Реализация метода notifyObservers для Pegas
void Pegas::notifyObservers(const std::string& loser) {
    for (auto& observer : observers) {
        observer->update(this->name, loser);
    }
}

// Реализация конструктора Dragon
Dragon::Dragon(Coordinates cords, std::string name) : NPC(cords, name) {}

// Реализация метода get_type для Dragon
std::string Dragon::get_type() const {
    return "Dragon";
}

// Реализация метода addObserver для Dragon
void Dragon::addObserver(std::shared_ptr<AbstractObserver> observer) {
    observers.push_back(observer);
}

// Реализация метода notifyObservers для Dragon
void Dragon::notifyObservers(const std::string& loser) {
    for (auto& observer : observers) {
        observer->update(this->name, loser);
    }
}
