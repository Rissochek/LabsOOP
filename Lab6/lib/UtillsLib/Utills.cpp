#include "Utills.h"

// Функция для получения имени из файла
std::string func_get_name_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::vector<std::string> names;
    std::string name;
    while (std::getline(file, name)) {
        names.push_back(name);
    }
    int index = rand() % names.size();  // Выбираем случайное имя из доступных
    return names[index];
}

// Функция для печати информации о NPC
void print_npc_info(std::vector<std::unique_ptr<NPC>>& npcs) {
    for (const auto& npc : npcs) {
        std::cout << "INFO: Type - " << npc->get_type() 
                  << "; Name - " << npc->get_name() 
                  << "; Coords - (" << npc->get_coords().x << "," << npc->get_coords().y << ")" 
                  << std::endl;
    }
}

// Функция для создания NPC из строки
std::unique_ptr<NPC> create_npc_from_line(const std::string& line) {
    std::istringstream stream(line);
    std::string type;
    float x, y;
    std::string name;

    stream >> type >> x >> y >> std::ws;
    std::getline(stream, name);  // Получаем имя, которое может содержать пробелы.

    Coordinates coords{x, y};

    if (type == "Knight") {
        return std::make_unique<Knight>(coords, name);
    } else if (type == "Pegas") {
        return std::make_unique<Pegas>(coords, name);
    } else if (type == "Dragon") {
        return std::make_unique<Dragon>(coords, name);
    } else {
        throw std::runtime_error("Unknown NPC type in file: " + type);
    }
}

// Функция для загрузки NPC из файла
std::vector<std::unique_ptr<NPC>> load_npcs_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for reading: " + filename);
    }

    std::vector<std::unique_ptr<NPC>> npcs;
    std::string line;
    while (std::getline(file, line)) {
        npcs.push_back(create_npc_from_line(line));
    }

    file.close();
    return npcs;
}

// Функция для сохранения NPC в файл
void save_npc_to_file(const std::vector<std::unique_ptr<NPC>>& npcs, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for writing: " + filename);
    }

    for (const auto& npc : npcs) {
        const Coordinates& coords = npc->get_coords();
        file << npc->get_type() << " " // Используем get_type()
             << coords.x << " " 
             << coords.y << " "
             << npc->get_name() << std::endl;
    }

    file.close();
}
