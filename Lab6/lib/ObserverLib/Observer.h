#pragma once

#include <string>
#include <iostream>
#include <fstream>

// Абстрактный класс Observer
class AbstractObserver {
public:
    virtual void update(const std::string& winner, const std::string& loser) = 0;
    virtual ~AbstractObserver() = default;
};

// Класс ConsoleObserver для вывода информации в консоль
class ConsoleObserver : public AbstractObserver {
public:
    void update(const std::string& winner, const std::string& loser) override;
};

// Класс FileObserver для записи информации в файл
class FileObserver : public AbstractObserver {
    std::string filename;
    std::ofstream file;
public:
    FileObserver(std::string fn);
    void update(const std::string& winner, const std::string& loser) override;
    ~FileObserver();
};


