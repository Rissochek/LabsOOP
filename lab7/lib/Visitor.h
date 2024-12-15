#pragma once
#include <cmath>
#include <vector>
#include <algorithm>
#include "Npc.h"
#include <random>
#include <chrono>
#include "Observer.h"

class Visitor {
public:
    void add_observer(AbstractObserver* observer) {
        observers.push_back(observer);
    }
    void engage(std::vector<std::shared_ptr<Npc>>& npcs) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine rng(seed);
        std::uniform_int_distribution dist(1, 6);

        for (size_t i = 0; i < npcs.size(); ++i) {
            for (size_t j = i + 1; j < npcs.size(); ++j) {
                auto left_npc = npcs[i];
                auto right_npc = npcs[j];

                if (!left_npc->is_alive() || !right_npc->is_alive()) {
                    continue;
                }

                double distance = std::sqrt(std::pow(left_npc->get_pos_x() - right_npc->get_pos_x(), 2) + std::pow(left_npc->get_pos_y() - right_npc->get_pos_y(), 2));

                bool left_won = left_npc->beats(*right_npc) && distance <= left_npc->get_attack_range() && dist(rng) > dist(rng);
                bool right_won = right_npc->beats(*left_npc) && distance <= right_npc->get_attack_range() && dist(rng) > dist(rng);

                if (left_won && right_won) {
                    announce(left_npc->get_name() + " and " + right_npc->get_name() + " destroyed each other in deadly battle.");
                    left_npc->kill();
                    right_npc->kill();
                }
                else if (left_won) {
                    announce(left_npc->get_name() + " beats " + right_npc->get_name());
                    right_npc->kill();
                }
                else if (right_won) {
                    announce(right_npc->get_name() + " beats " + left_npc->get_name());
                    left_npc->kill();
                }
                else {
                    continue;
                }
            }
        }
    }
private:
    void announce(const std::string& event) {
        for (auto observer : observers) {
            observer->handle_event(event);
        }
    }
private:
    std::vector<AbstractObserver*> observers;
};