#pragma once

#include <memory>
#include <string>
#include <fstream>
#include <vector>
#include "../NpcLib/Npc.h"  // Подключаем NPC, так как мы создаем их через фабрики

// Абстрактный класс для фабрики NPC
class AbstractFactory {
public:
    virtual std::unique_ptr<NPC> create_npc() = 0;
    virtual ~AbstractFactory() = default;
};

// Абстрактная фабрика для создания NPC с случайными параметрами
class AbstractRandomParametersFactory : public AbstractFactory {
protected:
    std::string creature_name;
    std::string filename;
    
public:
    AbstractRandomParametersFactory(std::string fn);
    virtual std::unique_ptr<NPC> create_npc() = 0;
};

// Функция для получения имени из файла
std::string func_get_name_from_file(const std::string& filename);

// Фабрика для создания рыцарей с случайными параметрами
class KnightRandomParametersFactory : public AbstractRandomParametersFactory {
    std::string knight_surname;
    std::string filename_surname;
    
public:
    KnightRandomParametersFactory(std::string fn, std::string fn_surname);
    std::unique_ptr<NPC> create_npc() override;
};

// Фабрика для создания Пегасов с случайными параметрами
class PegasRandomParametersFactory : public AbstractRandomParametersFactory {
public:
    PegasRandomParametersFactory(std::string fn);
    std::unique_ptr<NPC> create_npc() override;
};

// Фабрика для создания Драконов с случайными параметрами
class DragonRandomParametersFactory : public AbstractRandomParametersFactory {
public:
    DragonRandomParametersFactory(std::string fn);
    std::unique_ptr<NPC> create_npc() override;
};

