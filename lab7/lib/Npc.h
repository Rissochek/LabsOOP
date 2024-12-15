#pragma once
#include <string>
#include <cmath>
#include <memory>


struct Point {
public:
    Point() = default;
    Point(double x, double y) : x(x), y(y) {}
    void normalize() {
        x /= get_length();
        y /= get_length();
    }
    double get_length() const {
        return std::sqrt(x * x + y * y);
    }
    Point& operator+=(const Point& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    Point& operator-=(const Point& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    Point& operator*=(double scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }
    Point& operator/=(double scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }
    Point operator*(double scalar) {
        Point result = *this;
        result.x *= scalar;
        result.y *= scalar;
        return result;
    }
    Point operator/(double scalar) {
        Point result = *this;
        result.x /= scalar;
        result.y /= scalar;
        return result;
    }
    Point operator+(double scalar) {
        Point result = *this;
        result.x += scalar;
        result.y += scalar;
        return result;
    }
    Point operator-(double scalar) {
        Point result = *this;
        result.x -= scalar;
        result.y -= scalar;
        return result;
    }
public:
    double x;
    double y;
};

class Npc {
public:
    Npc(const std::string& name, double x, double y, float step_size, float attack_range)
        :
        name(name),
        pos({x, y}),
        step_size(step_size),
        attack_range(attack_range)
    {}
    const std::string& get_name() const noexcept { return name; }
    double get_pos_x() const noexcept { return pos.x; }
    double get_pos_y() const noexcept { return pos.y; }
    virtual std::string get_type() const = 0;
    bool is_alive() const { return isAlive; }
    void kill() { isAlive = false; }
    void move(Point dir) {
        dir.normalize();
        pos += dir * step_size;
    }
    float get_attack_range() const {
        return attack_range;
    }
    void set_position(const Point& p) {
        pos.x = p.x;
        pos.y = p.y;
    }
    virtual bool beats(const Npc& other) const = 0;
    virtual ~Npc() = default;
protected:
    std::string name;
    Point pos;
    bool isAlive = true;
    float step_size;
    float attack_range;
};

class Knight : public Npc {
public:
    Knight(const std::string& name, double x, double y)
        :
        Npc(name, x, y, 30, 10)
    {}
    virtual std::string get_type() const override {
        return "Knight";
    }
    virtual bool beats(const Npc& other) const override {
        return other.get_type() == "Dragon";
    }
};

class Dragon : public Npc {
public:
    Dragon(const std::string& name, double x, double y)
        :
        Npc(name, x, y, 50, 30)
    {}
    virtual std::string get_type() const override {
        return "Dragon";
    }
    virtual bool beats(const Npc& other) const override {
        return other.get_type() == "Pegas";
    }
};

class Pegas : public Npc {
public:
    Pegas(const std::string& name, double x, double y)
        :
        Npc(name, x, y, 30, 10)
    {}
    virtual std::string get_type() const override {
        return "Pegas";
    }
    virtual bool beats(const Npc&) const override {
        return false;
    }
};