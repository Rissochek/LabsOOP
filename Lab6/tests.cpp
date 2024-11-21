#include "lib/NpcLib/Npc.h"
#include "lib/VisitorLib/Visitor.h"
#include "lib/ObserverLib/Observer.h"
#include "lib/UtillsLib/Utills.h"
#include "lib/FactoryLib/Factory.h"
#include <gtest/gtest.h>
#include <vector>
#include <memory>
#include <sstream>

// Проверка конструктора NPC и методов получения координат и имени
TEST(NPCTest, CreateAndAccess) {
    Coordinates coords = {10.0f, 20.0f};
    Knight knight(coords, "Knight1");

    EXPECT_EQ(knight.get_type(), "Knight");
    EXPECT_EQ(knight.get_name(), "Knight1");
    EXPECT_FLOAT_EQ(knight.get_coords().x, 10.0f);
    EXPECT_FLOAT_EQ(knight.get_coords().y, 20.0f);
}

// Проверка фабрики создания случайных рыцарей
TEST(KnightFactoryTest, CreateRandomKnight) {
    KnightRandomParametersFactory factory("data/names/names.txt", "data/names/surnames.txt");

    auto knight = factory.create_npc();
    ASSERT_NE(knight, nullptr);
    EXPECT_EQ(knight->get_type(), "Knight");
    EXPECT_FALSE(knight->get_name().empty());
    auto coords = knight->get_coords();
    EXPECT_GE(coords.x, 0);
    EXPECT_LE(coords.x, 500);
    EXPECT_GE(coords.y, 0);
    EXPECT_LE(coords.y, 500);
}

// Проверка функции загрузки NPC из строки
TEST(LoadNPCFromLineTest, ValidInput) {
    std::string input = "Knight 100.0 200.0 Sir_Lancelot";
    auto npc = create_npc_from_line(input);

    ASSERT_NE(npc, nullptr);
    EXPECT_EQ(npc->get_type(), "Knight");
    EXPECT_EQ(npc->get_name(), "Sir_Lancelot");
    EXPECT_FLOAT_EQ(npc->get_coords().x, 100.0f);
    EXPECT_FLOAT_EQ(npc->get_coords().y, 200.0f);
}

// Проверка системы наблюдателей
TEST(ObserverTest, NotifyObservers) {
    auto console_observer = std::make_shared<ConsoleObserver>();
    Knight knight({100.0f, 200.0f}, "Knight1");
    knight.addObserver(console_observer);

    // Симуляция вызова уведомления
    testing::internal::CaptureStdout();
    knight.notifyObservers("Enemy");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Knight1 defeated Enemy\n");
}

// Проверка битвы между рыцарем и драконом
// TEST(BattleVisitorTest, BattleKnightVsDragon) {
//     std::vector<std::unique_ptr<NPC>> npcs;
//     npcs.push_back(std::make_unique<Knight>(Coordinates{100.0, 200.0}, "Knight1"));
//     npcs.push_back(std::make_unique<Dragon>(Coordinates{102.0, 202.0}, "Dragon1"));

//     BattleVisitor visitor(5.0f); // Дальность 5 единиц
//     visitor.battle(npcs);

//     ASSERT_EQ(npcs.size(), 1); // Проверяем, что один NPC был удален
//     EXPECT_EQ(npcs[0]->get_name(), "Dragon1"); // Ожидаем, что остался дракон
// }

// Проверка сохранения и загрузки NPC из файла
TEST(FileOperationsTest, SaveAndLoadNPCs) {
    std::vector<std::unique_ptr<NPC>> npcs;
    npcs.push_back(std::make_unique<Knight>(Coordinates{10.0, 20.0}, "Knight1"));
    npcs.push_back(std::make_unique<Dragon>(Coordinates{30.0, 40.0}, "Dragon1"));

    const std::string filename = "data/pre_created_npcs/npcs.txt";
    save_npc_to_file(npcs, filename);

    auto loaded_npcs = load_npcs_from_file(filename);
    ASSERT_EQ(loaded_npcs.size(), npcs.size());
    EXPECT_EQ(loaded_npcs[0]->get_type(), "Knight");
    EXPECT_EQ(loaded_npcs[0]->get_name(), "Knight1");
    EXPECT_EQ(loaded_npcs[1]->get_type(), "Dragon");
    EXPECT_EQ(loaded_npcs[1]->get_name(), "Dragon1");

    // Удаление временного файла
    std::remove(filename.c_str());
}
