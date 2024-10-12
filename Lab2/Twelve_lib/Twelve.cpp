#include "Twelve.h"
#include <iostream>
#include <cstddef>
#include <cmath>

Twelve::Twelve(): array_size(1), array(new unsigned char{0}){}

Twelve::Twelve(unsigned int decimal_value, bool is_negativ){
    size_t array_size = 10;
    unsigned char* array = new unsigned char[array_size]{0};
    int counter = 0;
    unsigned char remains;
    if (decimal_value != 0){
    while (decimal_value != 0){
        remains = decimal_value % 12;
        decimal_value /= 12;
        array[counter] = remains;
        counter += 1;
        if (counter >= array_size){
            array_size *= 2;
            unsigned char* buffer = new unsigned char[array_size]{0};
            for (int i = 0; i < array_size/2; i++){
                buffer[i] = array[i];
            }
            delete[] array;
            array = buffer;
        }
    }
    }else{
        array[0] = 0;
        counter = 1;
    }
    this->array = array;
    this->array_size = counter;
    this->is_negativ = is_negativ;
    return;
}

Twelve::Twelve(const Twelve& other){
    this->array_size = other.array_size;
    this->array = new unsigned char[this->array_size];
    for (int i = 0; i < array_size; i++){
        this->array[i] = other.array[i];
    }
    this->is_negativ = other.is_negativ;
    return;
}

Twelve Twelve::minus(const Twelve& other) const{
    int decimal_this = decimal_value(*this);
    int decimal_other = decimal_value(other);
    if (decimal_this - decimal_other >= 0){
        return Twelve(decimal_this - decimal_other, false); 
    }else{
        return Twelve(decimal_other - decimal_this, true);
    }
}

Twelve Twelve::plus(const Twelve& other) const{
    int decimal_this = decimal_value(*this);
    int decimal_other = decimal_value(other);
    if (decimal_this + decimal_other >= 0){
        return Twelve(decimal_this + decimal_other, false); 
    }else{
        return Twelve(static_cast<int>(fabs(decimal_other + decimal_this)), true);
    }
}

void Twelve::get_values(size_t& size, unsigned char*& arr, bool& is_negative){
    size = this->array_size;
    arr = this->array;
    is_negativ = this->is_negativ;
    return;
};

int Twelve::decimal_value(const Twelve& num) const{
    int value = 0;
    for (int i = 0; i < num.array_size; i++){
        value += num.array[i] * std::pow(12, i);
    }
    if (num.is_negativ == true){
        value = 0 - value;
    }
    return value;
}

bool Twelve::gt(const Twelve& other) const{
    if (decimal_value(*this) > decimal_value(other)){
        return true;
    }else{
        return false;
    }
}

bool Twelve::lt(const Twelve& other) const{
    if (decimal_value(*this) < decimal_value(other)){
        return true;
    }else{
        return false;
    }
}

bool Twelve::eq(const Twelve& other) const{
    if (decimal_value(*this) == decimal_value(other)){
        return true;
    }else{
        return false;
    }
}

Twelve::~Twelve() noexcept{
    this->array_size = 0;
    this->is_negativ = false;
    delete []this->array;
    this->array = nullptr;
    return;
}
