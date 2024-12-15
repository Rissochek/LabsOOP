#include "Observer.h"
#include "World.h"
#include "Visitor.h"
#include <random>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <shared_mutex>
#include <array>

std::atomic<bool> game_is_running{ true };
std::shared_mutex npc_mutex;

int main() {
    World world(45);
    Visitor visitor;
    ConsoleObserver console_observer;
    FileObserver file_observer("log.txt");

    visitor.add_observer(&console_observer);
    visitor.add_observer(&file_observer);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);
    std::uniform_real_distribution dist(0.0, world.get_size());

    std::uniform_int_distribution int_dist(0, 2);

    {
        const char* types[] = { "Knight", "Dragon", "Pegas" };
        std::array<int, 3> counters = { 0, 0, 0 };
        for (int i = 0; i < world.get_size() / 3; ++i) {
            int rand = int_dist(rng);
            std::string type = types[rand];

            world.add_npc(type, type + " " + std::to_string(counters[rand]++), dist(rng), dist(rng));
        }
    }

    std::cout << "Fighters in dungeon:\n";
    {
        std::shared_lock lock(npc_mutex);
        world.announce_fighters();
    }

    std::thread movement_thread([&]() {
        while (game_is_running) {
            {
                std::unique_lock lock(npc_mutex);
                world.move_npcs();
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });

    std::thread battle_thread([&]() {
        while (game_is_running) {
            {
                std::unique_lock lock(npc_mutex);
                world.engage(visitor);
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });

    std::thread display_thread([&]() {
        while (game_is_running) {
            {
                std::unique_lock lock(npc_mutex);
                world.print_map();
            }
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
        });

    std::this_thread::sleep_for(std::chrono::seconds(30));
    game_is_running = false;

    movement_thread.join();
    battle_thread.join();
    display_thread.join();

    std::cout << "\nRemaining Fighters:\n";
    {
        std::shared_lock lock(npc_mutex);
        world.print_map();
        world.announce_fighters();
    }

    return 0;
}