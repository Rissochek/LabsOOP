#include <string>
#include <iostream>
#include "vowel_lib/count_vowels.cpp"

int main()
{
    std::string input_string = "";
    std::getline(std::cin, input_string);
    std::cout << count_vowels_from_string(input_string);
    return 0;
}