#include "Observer.h"
#include <stdexcept>

// Реализация метода update для ConsoleObserver
void ConsoleObserver::update(const std::string& winner, const std::string& loser) {
    std::cout << winner << " defeated " << loser << std::endl;
}

// Реализация конструктора FileObserver
FileObserver::FileObserver(std::string fn) : filename(fn) {
    file.open(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }
}

// Реализация метода update для FileObserver
void FileObserver::update(const std::string& winner, const std::string& loser) {
    auto msg = winner + " defeated " + loser;
    if (file.is_open()) {
        file << msg << std::endl;
    } else {
        throw std::runtime_error("Failed to write to file: " + filename);
    }
}

// Деструктор для закрытия файла
FileObserver::~FileObserver() {
    if (file.is_open()) {
        file.close();
    }
}
