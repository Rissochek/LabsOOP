#include "Factory.h"

// Реализация конструктора AbstractRandomParametersFactory
AbstractRandomParametersFactory::AbstractRandomParametersFactory(std::string fn) : filename(fn) {}

// Реализация конструктора KnightRandomParametersFactory
KnightRandomParametersFactory::KnightRandomParametersFactory(std::string fn, std::string fn_surname)
    : AbstractRandomParametersFactory(fn), filename_surname(fn_surname) {}

// Реализация метода create_npc для KnightRandomParametersFactory
std::unique_ptr<NPC> KnightRandomParametersFactory::create_npc() {
    float x = static_cast<float>(rand() % 501);
    float y = static_cast<float>(rand() % 501);
    creature_name = func_get_name_from_file(filename);
    knight_surname = func_get_name_from_file(filename_surname);
    Coordinates coords{x, y};
    std::string fullname = creature_name + " " + knight_surname;
    return std::make_unique<Knight>(coords, fullname);
}

// Реализация конструктора PegasRandomParametersFactory
PegasRandomParametersFactory::PegasRandomParametersFactory(std::string fn)
    : AbstractRandomParametersFactory(fn) {}

// Реализация метода create_npc для PegasRandomParametersFactory
std::unique_ptr<NPC> PegasRandomParametersFactory::create_npc() {
    float x = static_cast<float>(rand() % 501);
    float y = static_cast<float>(rand() % 501);
    creature_name = func_get_name_from_file(filename);
    Coordinates coords{x, y};
    return std::make_unique<Pegas>(coords, creature_name);
}

// Реализация конструктора DragonRandomParametersFactory
DragonRandomParametersFactory::DragonRandomParametersFactory(std::string fn)
    : AbstractRandomParametersFactory(fn) {}

// Реализация метода create_npc для DragonRandomParametersFactory
std::unique_ptr<NPC> DragonRandomParametersFactory::create_npc() {
    float x = static_cast<float>(rand() % 501);
    float y = static_cast<float>(rand() % 501);
    creature_name = func_get_name_from_file(filename);
    Coordinates coords{x, y};
    return std::make_unique<Dragon>(coords, creature_name);
}
