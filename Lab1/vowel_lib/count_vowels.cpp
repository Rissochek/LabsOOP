#include <string>

int count_vowels_from_string(const std::string& input_string)
{
    int count = 0;
    for (char letter : input_string)
    {
        switch (std::tolower(letter))
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                count++;
                break;
        }
    }
    return count;
}