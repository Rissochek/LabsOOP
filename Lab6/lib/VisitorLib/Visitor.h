#pragma once
#include <memory>
#include <vector>
#include <string>
#include <cmath>
#include "../NpcLib/Npc.h"  // Подключаем NPC, так как мы работаем с ними

// Абстрактный класс Visitor
class Visitor { 
public:
    virtual void battle(std::vector<std::unique_ptr<NPC>>& npcs) = 0;
    virtual ~Visitor() = default;
};

// Класс BattleVisitor для проведения сражений
class BattleVisitor {
    float battle_range;

public:
    BattleVisitor(float range);
    void battle(std::vector<std::unique_ptr<NPC>>& npcs);

private:
    bool is_in_range(const NPC& npc1, const NPC& npc2) const;
    bool should_fight(const NPC& npc1, const NPC& npc2) const;
    std::pair<bool, bool> resolve_battle(NPC& npc1, NPC& npc2);
};


