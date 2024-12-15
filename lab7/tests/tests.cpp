#include <gtest/gtest.h>
#include "World.h"
#include "Factory.h"
#include "Npc.h"
#include "Visitor.h"
#include "Observer.h"
#include <fstream>
#include <memory>

// Тест создания NPC
TEST(NpcTest, CreateNpc) {
    auto knight = Factory::create_npc("Knight", "Knight1", 10.0, 20.0);
    EXPECT_EQ(knight->get_type(), "Knight");
    EXPECT_EQ(knight->get_name(), "Knight1");

}

// Тест движения NPC
TEST(NpcTest, MoveNpc) {
    auto knight = Factory::create_npc("Knight", "Knight1", 10.0, 20.0);
    Point direction(1.0, 1.0);
    knight->move(direction);
    EXPECT_NE(knight->get_pos_x(), 10.0);
    EXPECT_NE(knight->get_pos_y(), 20.0);
}

// Тест отображения карты мира
TEST(WorldTest, PrintMap) {
    World world(50.0);
    world.add_npc("Knight", "Knight1", 10.0, 20.0);
    testing::internal::CaptureStdout();
    world.print_map();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

// Тест фабрики NPC
TEST(FactoryTest, CreateNpc) {
    auto knight = Factory::create_npc("Knight", "Knight1", 10.0, 20.0);
    EXPECT_EQ(knight->get_type(), "Knight");
    EXPECT_EQ(knight->get_name(), "Knight1");
    EXPECT_DOUBLE_EQ(knight->get_pos_x(), 10.0);
    EXPECT_DOUBLE_EQ(knight->get_pos_y(), 20.0);
}
