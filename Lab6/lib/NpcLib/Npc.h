#pragma once

#include <string>
#include <vector>
#include <memory>
#include "../ObserverLib/Observer.h"

struct Coordinates
{
    float x;
    float y;
};

// Абстрактный класс NPC
class NPC {
protected:
    std::vector<std::shared_ptr<AbstractObserver>> observers;
    Coordinates npc_coords;
    std::string name;

public:
    NPC(Coordinates cords, std::string name);

    virtual std::string get_type() const = 0;

    virtual std::string get_name() const;
    virtual Coordinates get_coords() const;

    virtual void addObserver(std::shared_ptr<AbstractObserver> observer) = 0;
    virtual void notifyObservers(const std::string& loser) = 0;

    virtual ~NPC() = default;
};

// Класс Knight
class Knight : public NPC {
public:
    Knight(Coordinates cords, std::string name);

    std::string get_type() const override;
    void addObserver(std::shared_ptr<AbstractObserver> observer) override;
    void notifyObservers(const std::string& loser) override;
};

// Класс Pegas
class Pegas : public NPC {
public:
    Pegas(Coordinates cords, std::string name);

    std::string get_type() const override;
    void addObserver(std::shared_ptr<AbstractObserver> observer) override;
    void notifyObservers(const std::string& loser) override;
};

// Класс Dragon
class Dragon : public NPC {
public:
    Dragon(Coordinates cords, std::string name);

    std::string get_type() const override;
    void addObserver(std::shared_ptr<AbstractObserver> observer) override;
    void notifyObservers(const std::string& loser) override;
};


