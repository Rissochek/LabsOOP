#pragma once
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include "../NpcLib/Npc.h"  // Необходимо подключить, так как функции работают с классами NPC и его производными.

std::string func_get_name_from_file(const std::string& filename);

void print_npc_info(std::vector<std::unique_ptr<NPC>>& npcs);

std::unique_ptr<NPC> create_npc_from_line(const std::string& line);

std::vector<std::unique_ptr<NPC>> load_npcs_from_file(const std::string& filename);

void save_npc_to_file(const std::vector<std::unique_ptr<NPC>>& npcs, const std::string& filename);
