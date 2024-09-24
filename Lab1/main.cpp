#include <string>
#include <iostream>
#include "vowel_lib/vowel_lib.h"

int main()
{
    std::string input_string = "";
    std::getline(std::cin, input_string);
    std::cout << count_vowels_from_string(input_string);
    return 0;
}