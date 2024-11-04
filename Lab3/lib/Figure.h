#pragma once
#include <stddef.h>
#include <iostream>
typedef struct
{
    double x;
    double y;
} Point;


class Figure{
    public:
        Figure(size_t points_count);
        Figure(size_t points_count, Point* arr);
        virtual Point found_center(){return Point{0,0};};
        bool operator ==(const Figure& other) const;
        Figure& operator = (const Figure& other);
        Figure& operator = (Figure&& other);
        friend std::ostream& operator << (std::ostream& os, const Figure& obj);
        friend std::istream& operator >> (std::istream& is, Figure& obj);
        virtual operator double() const {return 0;};
        virtual ~Figure();
    protected:
        size_t points_count;
        Point* points_array;
        double area = 0.0;
        double center = 0.0;
};

class Trapeze: public Figure{
    public:
        Trapeze(size_t points_count):Figure(points_count){};
        Trapeze(size_t points_count, Point* arr):Figure(points_count, arr){};
        Point found_center();
        operator double() const;
        ~Trapeze(){};
};

class Rhomb: public Figure{
    public:
        Rhomb(size_t points_count):Figure(points_count){};
        Rhomb(size_t points_count, Point* arr):Figure(points_count, arr){};
        Point found_center();
        operator double() const;
        ~Rhomb(){};
};

class Pentagon: public Figure{
    public:
        Pentagon(size_t points_count):Figure(points_count){};
        Pentagon(size_t points_count, Point* arr):Figure(points_count, arr){};
        Point found_center();
        operator double() const;
        ~Pentagon(){};
};



