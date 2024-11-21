#include "Visitor.h"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstdlib>

// Реализация конструктора BattleVisitor
BattleVisitor::BattleVisitor(float range) : battle_range(range) {}

// Основной метод для проведения сражений
void BattleVisitor::battle(std::vector<std::unique_ptr<NPC>>& npcs) {
    for (size_t i = 0; i < npcs.size(); ++i) {
        for (size_t j = i + 1; j < npcs.size();) {
            if (is_in_range(*npcs[i], *npcs[j])) {
                if (should_fight(*npcs[i], *npcs[j])) {
                    std::cout << "Battle: " << npcs[i]->get_name() << " (" << npcs[i]->get_type()
                              << ") vs " << npcs[j]->get_name() << " (" << npcs[j]->get_type() << ")\n";

                    auto result = resolve_battle(*npcs[i], *npcs[j]);
                    if (result.first && result.second) {
                        npcs[j]->notifyObservers(npcs[i]->get_name());
                        npcs[i]->notifyObservers(npcs[j]->get_name());
                        npcs.erase(npcs.begin() + i);
                        --i;
                        npcs.erase(npcs.begin() + j - 1);
                        break;
                    }

                    if (result.first) { // Первый NPC погиб
                        npcs[j]->notifyObservers(npcs[i]->get_name());
                        npcs.erase(npcs.begin() + i);
                        --i;
                        break;
                    }
                    if (result.second) { // Второй NPC погиб
                        npcs[i]->notifyObservers(npcs[j]->get_name());
                        npcs.erase(npcs.begin() + j);
                    } else {
                        ++j;
                    }
                } else {
                    ++j;
                }
            } else {
                ++j;
            }
        }
    }
}

// Проверка расстояния между NPC
bool BattleVisitor::is_in_range(const NPC& npc1, const NPC& npc2) const {
    const Coordinates& c1 = npc1.get_coords();
    const Coordinates& c2 = npc2.get_coords();
    float distance = std::sqrt(std::pow(c2.x - c1.x, 2) + std::pow(c2.y - c1.y, 2));
    return distance <= battle_range;
}

// Проверка, могут ли два NPC сражаться
bool BattleVisitor::should_fight(const NPC& npc1, const NPC& npc2) const {
    if (npc1.get_type() == "Dragon" && npc2.get_type() == "Pegas") {
        return true;  // Дракон атакует пегаса
    }
    if (npc1.get_type() == "Pegas" || npc2.get_type() == "Pegas") {
        return false;  // Пегас не участвует в боях
    }
    if ((npc1.get_type() == "Knight" && npc2.get_type() == "Dragon") || (npc1.get_type() == "Dragon" && npc2.get_type() == "Knight")) {
        return true;  // Рыцарь и дракон могут сражаться
    }
    return false;
}

// Логика исхода боя
std::pair<bool, bool> BattleVisitor::resolve_battle(NPC& npc1, NPC& npc2) {
    if (npc1.get_type() == "Knight" && npc2.get_type() == "Dragon") {
        size_t random_val = rand() % 2;
        return (random_val == 0) ? std::make_pair(false, true) : std::make_pair(true, true);
    }
    if (npc1.get_type() == "Dragon" && npc2.get_type() == "Pegas") {
        return std::make_pair(false, true);  // Дракон съедает пегаса
    }
    if (npc1.get_type() == "Dragon" && npc2.get_type() == "Knight") {
        size_t random_val = rand() % 2;
        return (random_val == 0) ? std::make_pair(true, false) : std::make_pair(true, true);
    }
    return std::make_pair(false, false);  // Если бой не состоялся — никто не умирает
}
