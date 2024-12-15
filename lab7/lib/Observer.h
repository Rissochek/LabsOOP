#pragma once
#include <fstream>
#include <iostream>
#include <string>

class AbstractObserver {
public:
    virtual void handle_event(const std::string& event) = 0;
    virtual ~AbstractObserver() = default;
};

class ConsoleObserver : public AbstractObserver {
public:
    virtual void handle_event(const std::string& event) override {
        std::cout << event << std::endl;
    }
};

class FileObserver : public AbstractObserver {
public:
    FileObserver(const std::string& filename)
        :
        logFile(filename)
    {}
    virtual void handle_event(const std::string& event) override {
        logFile << event << std::endl;
    }
    ~FileObserver() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
private:
    std::ofstream logFile;
};