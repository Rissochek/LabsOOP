#pragma once
#include <cstddef>

class Twelve{
    size_t array_size;
    unsigned char *array;
    bool is_negativ;

    public:
        Twelve();
        Twelve(unsigned int decimal_value, bool is_negativ);
        Twelve(const Twelve& other);

        Twelve minus(const Twelve& other) const;
        Twelve plus(const Twelve& other) const;

        bool gt(const Twelve& other) const;
        bool lt(const Twelve& other) const;
        bool eq(const Twelve& other) const;

        void get_values(size_t& size, unsigned char*& arr, bool& is_negative);
        int decimal_value(const Twelve& num) const;

        virtual ~Twelve() noexcept;
};