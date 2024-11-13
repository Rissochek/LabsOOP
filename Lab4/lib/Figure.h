#include <iostream>
#include <type_traits>
#include <memory>
#include <stddef.h>


template <class T = double>
concept scalar = std::is_scalar_v<T>;

template <scalar T>
class Figure;
template <scalar T>
class Trapeze;
template <scalar T>
class Rhomb;
template <scalar T>
class Pentagon;
template <class U>
class Array;

template <scalar T = double>
class Point{
        T x;
        T y;
    public:
        friend class Figure<T>;
        friend class Trapeze<T>;
        friend class Rhomb<T>;
        friend class Pentagon<T>;

        template <class U>
        friend class Array;
        Point(): x{0}, y{0} {};
        Point(T x, T y): x{x}, y{y} {};
        template <scalar U>
        friend std::ostream& operator << (std::ostream& os, const Point& obj);
        void print_point(){std::cout << "Point = (" << this->x << "," << this->y << ")" <<std::endl;}
        void get_point(T& a, T& b){a = this->x; b = this->y;}
};

template <class T>
class Array{
    std::shared_ptr<std::shared_ptr<T>[]> arr;
    size_t size_of_array = 0;
    public:
        Array(){arr = nullptr, size_of_array = 0;};
        Array(size_t size_of_array);
        Array(size_t size_of_array, std::shared_ptr<std::shared_ptr<T>[]> arr);
        Array(size_t size_of_array, std::shared_ptr<T[]> arr);
        void print_array_figures_characteristics();
        void print_array_area_sum();
        double get_array_area_sum();
        void resize(size_t new_size);
};

template <scalar T = double>
class Figure{
    template <class U>
    friend class Array;
    public:
    Figure(size_t points_count);
    Figure(size_t points_count, std::unique_ptr<Point<T>[]>&& arr);
    virtual Point<T> found_center(){return Point<T>{0,0};};
    bool operator ==(const Figure& other) const;
    Figure& operator = (const Figure& other);
    Figure& operator = (Figure&& other);
    template <scalar U>
    friend std::ostream& operator << (std::ostream& os, const Figure<U>& obj);
    template <scalar U>
    friend std::istream& operator >> (std::istream& is, Figure<U>& obj);
    virtual operator double() {return 0;};
    protected:
        size_t points_count;
        std::unique_ptr<Point<T>[]> points_array;
        double area = 0.0;
        double center = 0.0;
};

template<scalar T = double>
class Trapeze: public Figure<T>{
    template <class U>
    friend class Array;
    public:
        Trapeze(size_t points_count):Figure<T>(points_count){};
        Trapeze(size_t points_count, std::unique_ptr<Point<T>[]>&& arr):Figure<T>(points_count, std::move(arr)){};
        Point<T> found_center();
        operator double();
};

template<scalar T = double>
class Rhomb: public Figure<T>{
    template <class U>
    friend class Array;
    public:
        Rhomb(size_t points_count):Figure<T>(points_count){};
        Rhomb(size_t points_count, std::unique_ptr<Point<T>[]>&& arr):Figure<T>(points_count, std::move(arr)){};
        Point<T> found_center();
        operator double();
};

template<scalar T = double>
class Pentagon: public Figure<T>{
    template <class U>
    friend class Array;
    public:
        Pentagon(size_t points_count):Figure<T>(points_count){};
        Pentagon(size_t points_count, std::unique_ptr<Point<T>[]>&& arr):Figure<T>(points_count, std::move(arr)){};
        Point<T> found_center();
        operator double();
};

template <scalar T>
std::ostream& operator << (std::ostream& os, const Point<T>& obj){
    os << "center point " <<" = (" << obj.x << "," << obj.y << ")" << std::endl;
    return os;
}

template <class T>
Array<T>::Array(size_t size_of_array){
    this->arr = std::make_shared<T[]>(size_of_array);
    this->size_of_array = size_of_array;
}

template <class T>
Array<T>::Array(size_t size_of_array, std::shared_ptr<std::shared_ptr<T>[]> arr){
    this->arr = arr;
    this->size_of_array = size_of_array;
}


template <class T>
void Array<T>::print_array_figures_characteristics() {
    for (size_t i = 0; i < this->size_of_array; i++) {
        std::cout << "Figure " << i << ":" << std::endl;
        const auto& points_array = this->arr[i]->points_array;
        Point center{0,0};
        for (size_t j = 0; j < this->arr[i]->points_count; j++) {
            std::cout << "Point " << j << " = (" << points_array[j].x << "," << points_array[j].y << ")" << std::endl;
            center.x += points_array[j].x;
            center.y += points_array[j].y;
        }
        std::cout << "area = " << double(*(this->arr[i]).get()) << std::endl;
        center.x /= this->arr[i]->points_count;
        center.y /= this->arr[i]->points_count;
        std::cout << "center = {" << center.x << "," << center.y << "}" << std::endl;
    }
}

template <class T>
void Array<T>::print_array_area_sum(){
    double area_sum = 0;
    for (size_t i = 0; i < this->size_of_array; i++){
        area_sum += double(*(this->arr[i].get()));
    }
    std::cout << "area sum of array = " << area_sum << std::endl;
}

template <class T>
double Array<T>::get_array_area_sum(){
    double area_sum = 0;
    for (size_t i = 0; i < this->size_of_array; i++){
        area_sum += double(*(this->arr[i].get()));
    }
    return area_sum;
}

template <class T>
void Array<T>::resize(size_t new_size){
    std::shared_ptr<std::shared_ptr<T>[]> new_arr = std::make_shared<std::shared_ptr<T>[]>(new_size);
    for (size_t i = 0; i < std::min(this->size_of_array, new_size); ++i) {
        new_arr[i] = std::move(arr[i]);
    }
    this->arr = new_arr;
    this->size_of_array = new_size;
}

template <scalar T>
Figure<T>::Figure(size_t points_count){
    this->points_array = std::make_unique<Point<T>[]>(points_count);
    this->points_count = points_count;
}

template <scalar T>
Figure<T>::Figure(size_t points_count, std::unique_ptr<Point<T>[]>&& arr){
    this->points_array = std::make_unique<Point<T>[]>(points_count);
    this->points_count = points_count;
    for (size_t i = 0; i < this->points_count; i++){
        this->points_array[i] = arr[i];
    }
}

template <scalar T>
bool Figure<T>::operator ==(const Figure& other) const{
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

template <scalar T>
Figure<T>& Figure<T>::operator =(const Figure& other){
    if (&other == this){
        return *this;
    }

    this->points_array = std::make_unique<Point<T>[]>(other.points_count);
    for (size_t i = 0; i < other.points_count; ++i) {
        this->points_array[i] = other.points_array[i];
    }
    this->points_count = other.points_count;
    return *this;
}

template <scalar T>
Figure<T>& Figure<T>::operator =(Figure&& other){
    if (&other == this){
        return *this;
    }

    this->points_array = other.points_array;
    this->points_count = other.points_count;

    other.points_array = nullptr;
    other.points_count = 0;
    return *this;
}
template <scalar T>
std::ostream& operator << (std::ostream& os, const Figure<T>& obj){
    for (size_t i = 0; i < obj.points_count; i++){
        os << "Point " << i << " = (" << obj.points_array[i].x << "," << obj.points_array[i].y << ")" << std::endl;
    }
    return os;
}

template <scalar T>
std::istream& operator >>(std::istream& is, Figure<T>& obj) {
    for (size_t i = 0; i < obj.points_count; i++) {
        std::cout << "Point " << i+1 << ":";
        double x, y;
        is >> x >> y;
        obj.points_array[i] = Point<T>{static_cast<T>(x), static_cast<T>(y)};
    }
    return is;
}


template <scalar T>
Point<T> Trapeze<T>::found_center(){
    std::unique_ptr<Point<T>[]> arr = std::move(this->points_array);
    Point<T> center = Point<T>{0,0};
    center.x = (arr[0].x + arr[1].x + arr[2].x + arr[3].x)/4.0;
    center.y = (arr[0].y + arr[1].y + arr[2].y + arr[3].y)/4.0;
    this->points_array = std::move(arr);
    return center;
}

template <scalar T>
Trapeze<T>::operator double(){
    std::unique_ptr<Point<T>[]> arr = std::move(this->points_array);
    double area = 0.5*abs(arr[0].x*arr[1].y + arr[1].x*arr[2].y + arr[2].x*arr[3].y + arr[3].x*arr[0].y - arr[0].y*arr[1].x - arr[1].y*arr[2].x - arr[2].y*arr[3].x - arr[3].y * arr[0].x);
    this->points_array = std::move(arr);
    return area;
}

template <scalar T>
Point<T> Rhomb<T>::found_center(){
    std::unique_ptr<Point<T>[]> arr = std::move(this->points_array);
    Point<T> center = Point<T>{0,0};
    center.x = (arr[0].x + arr[1].x + arr[2].x + arr[3].x)/4.0;
    center.y = (arr[0].y + arr[1].y + arr[2].y + arr[3].y)/4.0;
    this->points_array = std::move(arr);
    return center;
}

template <scalar T>
Rhomb<T>::operator double(){
    std::unique_ptr<Point<T>[]> arr = std::move(this->points_array);
    double area = 0.5*abs(arr[0].x*arr[1].y + arr[1].x*arr[2].y + arr[2].x*arr[3].y + arr[3].x*arr[0].y - arr[0].y*arr[1].x - arr[1].y*arr[2].x - arr[2].y*arr[3].x - arr[3].y * arr[0].x);
    this->points_array = std::move(arr);
    return area;
}

template <scalar T>
Point<T> Pentagon<T>::found_center(){
    std::unique_ptr<Point<T>[]> arr = std::move(this->points_array);
    Point center = Point{0,0};
    center.x = (arr[0].x + arr[1].x + arr[2].x + arr[3].x + arr[4].x)/5.0;
    center.y = (arr[0].y + arr[1].y + arr[2].y + arr[3].y + arr[4].y)/5.0;
    this->points_array = std::move(arr);
    return center;
}

template <scalar T>
Pentagon<T>::operator double(){
    std::unique_ptr<Point<T>[]> arr = std::move(this->points_array);
    double area = 0.5*abs(arr[0].x*arr[1].y + arr[1].x*arr[2].y + arr[2].x*arr[3].y + arr[3].x*arr[4].y + arr[4].x*arr[0].y - arr[0].y*arr[1].x - arr[1].y*arr[2].x - arr[2].y*arr[3].x - arr[3].y*arr[4].x - arr[4].y*arr[0].x);
    this->points_array = std::move(arr);
    return area;
}