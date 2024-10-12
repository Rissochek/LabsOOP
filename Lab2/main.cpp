#include <iostream>
#include "Twelve_lib/Twelve.h"

int main(){
    Twelve num = Twelve(20, false);
    Twelve num2 = Twelve(15, false);
    size_t array_size;
    bool is_negative;
    unsigned char* array;

    Twelve result = num.plus(num2);
    result.get_values(array_size, array, is_negative);
    std::cout << "num - num2: " << std::endl;
    for (int i = 0; i < array_size; i++){
        std::cout << static_cast<int>(array[i]) <<" ";
    }
    std::cout << std::endl; 
    result = num.minus(num2);
    result.get_values(array_size, array, is_negative);
    std::cout << "num + num2: " << std::endl;
    for (int i = 0; i < array_size; i++){
        std::cout << static_cast<int>(array[i]) <<" ";
    }
    std::cout << std::endl;

    std::cout << num.eq(num2)<< std::endl;;
    std::cout << num.gt(num2)<< std::endl;;
    std::cout << num.lt(num2)<< std::endl;;

    return 0;
}