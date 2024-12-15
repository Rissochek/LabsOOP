#pragma once
#include <vector>
#include "Factory.h"
#include "Npc.h"
#include "Visitor.h"
#include <random>
#include <chrono>

class World {
public:
    World(double size) : world_size(size) {}
    void add_npc(const std::string& type, const std::string& name, double x, double y) {
        npcs.push_back(Factory::create_npc(type, name, x, y));
    }
    void announce_fighters() const {
        for (const auto& c : npcs) {
            if (!c->is_alive())
                continue;

            std::cout << c->get_type() << " '" << c->get_name() << "' ("
                << c->get_pos_x() << ", " << c->get_pos_y() << ")\n";
        }
    }
    void get_world_from_file(const std::string& filename) const {
        std::ofstream fs(filename);
        for (const auto& c : npcs) {
            fs << c->get_type() << " " << c->get_name() << " "
                << c->get_pos_x() << " " << c->get_pos_y() << "\n";
        }
    }
    void load_world_to_file(const std::string& filename) {
        std::ifstream fs(filename);
        std::string type, name;
        double x, y;
        while (fs >> type >> name >> x >> y) {
            add_npc(type, name, x, y);
        }
    }
    void engage(Visitor& visitor) {
        visitor.engage(npcs);
    }
    void move_npcs() {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine rng(seed);
        std::uniform_real_distribution dist(-1.0, 1.0);

        for (auto c : npcs) {
            Point dir = Point{ dist(rng), dist(rng) };
            c->move(dir);

            c->set_position(Point{ std::clamp(c->get_pos_x(), 0.0, world_size), std::clamp(c->get_pos_y(), 0.0, world_size) });
        }
    }
    void print_map() const {
        int x_size = int(world_size);
        int y_size = int(world_size);

        for (int i = 0; i <= x_size + 2; ++i) {
            std::cout << '-';
        }
        std::cout << '\n';

        for (int i = 0; i <= y_size; ++i) {
            std::cout << '|';
            for (int j = 0; j <= x_size; ++j) {
                bool printed = false;
                for (auto c : npcs) {
                    if (!c->is_alive())
                        continue;

                    printed = true;
                    if ((int)c->get_pos_x() == j && (int)c->get_pos_y() == i) {
                        if (c->get_type() == "Dragon") {
                            std::cout << '#';
                            break;
                        }
                        else if (c->get_type() == "Knight") {
                            std::cout << '_';
                            break;
                        }
                        else if (c->get_type() == "Pegas") {
                            std::cout << '@';
                            break;
                        }
                    }
                    else {
                        printed = false;
                    }
                }
                if (!printed) {
                    std::cout << ' ';
                }
            }
            std::cout << '|';
            std::cout << '\n';
        }

        for (int i = 0; i <= x_size + 2; ++i) {
            std::cout << '-';
        }
        std::cout << '\n';
    }
    double get_size() const {
        return world_size;
    }
private:
    double world_size;
    std::vector<std::shared_ptr<Npc>> npcs;
};