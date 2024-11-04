#include <iostream>
#include <cstddef>
#include "lib/Figure.h"

int main(){
    const int n = 2;
    Figure** figures = new Figure*[n];
    double area_sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        figures[i] = new Trapeze(4);
        std::cin >> *figures[i];
        area_sum += double(*figures[i]);
    }
    for (size_t i = 0; i < n; i++)
    {
        std::cout << *figures[i];
        Point p = figures[i]->found_center();
        std::cout << p.x << " " << p.y << std::endl;
        std::cout << double(*figures[i]) << std::endl;
    }
    std::cout << area_sum << std::endl;

    // delete figures[0];
    // figures[0] = nullptr;
    // for (size_t i = 0; i < n; i++)
    // {
    //     if (figures[i] != nullptr){
    //         std::cout << *figures[i];
    //         Point p = figures[i]->found_center();
    //         std::cout << p.x << " " << p.y << std::endl;
    //         std::cout << double(*figures[i]) << std::endl;
    //     }
    // }
    // return 0;
    //figures[1] = figures[0];
    *figures[0] = std::move(*figures[1]);
    figures[1] = nullptr;
    for (size_t i = 0; i < n; i++)
    {
        if (figures[i] != nullptr){
            std::cout << *figures[i];
            Point p = figures[i]->found_center();
            std::cout << p.x << " " << p.y << std::endl;
            std::cout << double(*figures[i]) << std::endl;
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        delete figures[i];
    }
    delete[]figures;

    // Trapeze trap1 = Trapeze(4);
    // Trapeze trap2 = Trapeze(4);

    // Figure** figures = new Figure*[2];
    // figures[0] = &trap1;
    // figures[1] = &trap2;
    // for (size_t i = 0; i < 2; i++)
    //     {
    //         figures[i] = new Trapeze(4);
    //         std::cin >> *figures[i];
    //     }
    // for (size_t i = 0; i < 2; i++)
    //     {
    //         std::cout << *figures[i];
    //         Point p = figures[i]->found_center();
    //         std::cout << p.x << " " << p.y << std::endl;
    //         std::cout << double(*figures[i]) << std::endl;
    //     }
    return 0;
}
