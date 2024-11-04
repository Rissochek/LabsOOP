#include "Figure.h"
#include <cstddef>
#include <vector>
#include <iostream>
#include <math.h>

Figure::Figure(size_t points_count){
    this->points_array = new Point[points_count];
    this->points_count = points_count;
}
Figure::Figure(size_t points_count, Point* arr){
    this->points_array = new Point[points_count];
    this->points_count = points_count;
    for (size_t i = 0; i < this->points_count; i++){
        this->points_array[i] = arr[i];
    }
}

bool Figure::operator ==(const Figure& other) const{
    bool flag = false;
    if (this->points_count == other.points_count){
        for (size_t i = 0; i < this->points_count; i++){
            for (size_t j = 0; j < other.points_count; j++){
                if (this->points_array[i].x == other.points_array[j].x && this->points_array[i].y == other.points_array[j].y){
                    flag = true;
                }
            }
            if (flag == false){
                return false;
            }else{
                flag = false;
            }
        }
    }else{
        return false;
    }
    return true;
}

Figure& Figure::operator =(const Figure& other){
    if (&other == this){
        return *this;
    }
    delete this->points_array;

    this->points_array = new Point[other.points_count];
    for (size_t i = 0; i < other.points_count; ++i) {
        this->points_array[i] = other.points_array[i];
    }
    this->points_count = other.points_count;
    return *this;
}

Figure& Figure::operator =(Figure&& other){
    if (&other == this){
        return *this;
    }
    delete this->points_array;

    this->points_array = other.points_array;
    this->points_count = other.points_count;

    other.points_array = nullptr;
    other.points_count = 0;
    return *this;
}

std::ostream& operator <<(std::ostream& os, const Figure& obj){
    for (size_t i = 0; i < obj.points_count; i++){
        os << "Point " << i << " = (" << obj.points_array[i].x << "," << obj.points_array[i].y << ")" << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Figure& obj) {
    for (size_t i = 0; i < obj.points_count; i++) {
        std::cout << "Point " << i+1 << ":";
        double x, y;
        is >> x >> y;
        obj.points_array[i] = Point{x, y};
    }
    return is;
}

Figure::~Figure(){
    delete[]this->points_array;
    this->points_array = nullptr;
};

Point Trapeze::found_center(){
    Point* arr = this->points_array;
    Point center = Point{0,0};
    center.x = (arr[0].x + arr[1].x + arr[2].x + arr[3].x)/4.0;
    center.y = (arr[0].y + arr[1].y + arr[2].y + arr[3].y)/4.0;
    return center;
}

Trapeze::operator double() const{
    Point* arr = this->points_array;
    double area = 0.5*abs(arr[0].x*arr[1].y + arr[1].x*arr[2].y + arr[2].x*arr[3].y + arr[3].x*arr[0].y - arr[0].y*arr[1].x - arr[1].y*arr[2].x - arr[2].y*arr[3].x - arr[3].y * arr[0].x);
    return area;
}

Point Rhomb::found_center(){
    Point* arr = this->points_array;
    Point center = Point{0,0};
    center.x = (arr[0].x + arr[1].x + arr[2].x + arr[3].x)/4.0;
    center.y = (arr[0].y + arr[1].y + arr[2].y + arr[3].y)/4.0;
    return center;
}

Rhomb::operator double() const{
    Point* arr = this->points_array;
    double area = 0.5*abs(arr[0].x*arr[1].y + arr[1].x*arr[2].y + arr[2].x*arr[3].y + arr[3].x*arr[0].y - arr[0].y*arr[1].x - arr[1].y*arr[2].x - arr[2].y*arr[3].x - arr[3].y * arr[0].x);
    return area;
}

Point Pentagon::found_center(){
    Point* arr = this->points_array;
    Point center = Point{0,0};
    center.x = (arr[0].x + arr[1].x + arr[2].x + arr[3].x + arr[4].x)/5.0;
    center.y = (arr[0].y + arr[1].y + arr[2].y + arr[3].y + arr[4].y)/5.0;
    return center;
}

Pentagon::operator double() const{
    Point* arr = this->points_array;
    double area = 0.5*abs(arr[0].x*arr[1].y + arr[1].x*arr[2].y + arr[2].x*arr[3].y + arr[3].x*arr[4].y + arr[4].x*arr[0].y - arr[0].y*arr[1].x - arr[1].y*arr[2].x - arr[2].y*arr[3].x - arr[3].y*arr[4].x - arr[4].y*arr[0].x);
    return area;
}

// int main(){
//     Point *arr = new Point[4];
//     arr[0] = Point{1,1};arr[1] = Point{3,5};arr[2] = Point{7,5};arr[3] = Point{9,1};
//     Point *arr2 = new Point[4];
//     arr2[0] = Point{1,1};arr2[1] = Point{7,5};arr2[2] = Point{3,5};arr2[3] = Point{9,1};
//     Trapeze trap1(4, arr);
//     Trapeze trap2(4, arr2);
//     if (trap1 == trap2){
//         std::cout << "True" << std::endl;
//     }
//     return 0;
// }