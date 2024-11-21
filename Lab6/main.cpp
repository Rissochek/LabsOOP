#include "lib/NpcLib/Npc.h"
#include "lib/VisitorLib/Visitor.h"
#include "lib/ObserverLib/Observer.h"
#include "lib/UtillsLib/Utills.h"
#include "lib/FactoryLib/Factory.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(std::time(nullptr));

    KnightRandomParametersFactory knightFactory("data/names/names.txt", "data/names/surnames.txt");
    PegasRandomParametersFactory pegasFactory("data/names/creatures_names.txt");
    DragonRandomParametersFactory dragonFactory("data/names/creatures_names.txt");

    // Создаем наблюдателей
    auto consoleObserver = std::make_shared<ConsoleObserver>();
    auto fileObserver = std::make_shared<FileObserver>("data/logs/battle_log.txt");

    // Генерация NPC
    std::vector<std::unique_ptr<NPC>> npcs;
    for (int i = 0; i < 5; ++i) {
        auto knight = knightFactory.create_npc();
        knight->addObserver(consoleObserver);
        knight->addObserver(fileObserver);
        npcs.push_back(std::move(knight));

        auto pegas = pegasFactory.create_npc();
        pegas->addObserver(consoleObserver);
        pegas->addObserver(fileObserver);
        npcs.push_back(std::move(pegas));

        auto dragon = dragonFactory.create_npc();
        dragon->addObserver(consoleObserver);
        dragon->addObserver(fileObserver);
        npcs.push_back(std::move(dragon));
    }

    // Печать информации о созданных NPC
    std::cout << "=== Список созданных NPC ===" << std::endl;
    print_npc_info(npcs);

    // Сохранение NPC в файл
    save_npc_to_file(npcs, "data/created_npcs/npcs.txt");
    std::cout << "NPC сохранены в файл 'npcs.txt'.\n";

    // Загрузка NPC из файла
    std::cout << "\n=== Загрузка NPC из файла ===" << std::endl;
    auto loaded_npcs = load_npcs_from_file("data/pre_created_npcs/npcs.txt");
    print_npc_info(loaded_npcs);

    // Запуск битв
    std::cout << "\n=== Запуск битв ===" << std::endl;
    BattleVisitor battleVisitor(100.0f); // Указываем диапазон битв
    battleVisitor.battle(npcs);

    // Итоговый список выживших
    std::cout << "\n=== Выжившие после битв ===" << std::endl;
    print_npc_info(npcs);

    return 0;
}
