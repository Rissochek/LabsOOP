#include <iostream>
#include <cstddef>
#include <type_traits>
#include <memory>
#include "lib/Figure.h"

int main(){
    std::unique_ptr<Point<int>[]> point = std::make_unique<Point<int>[]>(4);
    point[0] = Point<int>{1,1}; point[1] = Point<int>{3,5}; point[2] = Point<int>{7,5}; point[3] = Point<int>{9,1};
    Trapeze<int> trap1(4, std::move(point));
    std::cout << double(trap1) << std::endl;
    const int n = 1;
    std::shared_ptr<std::shared_ptr<Figure<int>>[]> figures = std::make_shared<std::shared_ptr<Figure<int>>[]>(n);
    for (size_t i = 0; i < n; i++) {
        figures[i] = std::make_shared<Trapeze<int>>(4);
        std::cin >> *(figures[i].get());
        std::cout << double(*(figures[i].get())) << std::endl;
        std::cout << *(figures[i].get());
    }    
    return 0;
}








    // const size_t n = 2;
    // std::shared_ptr<std::shared_ptr<Figure<double>>[]> figures = std::make_shared<std::shared_ptr<Figure<double>>[]>(n);
    // for (size_t i = 0; i < n; i++){
    //     figures[i] = std::make_shared<Trapeze<double>>(4);
    //     std::cin >> *(figures[i].get());
    // }
    // Array<Figure<double>> arr = Array<Figure<double>>{2, figures};
    // arr.print_array_figures_characteristics();
    // arr.print_array_area_sum();
    // return 0;

    // const size_t n = 2;
    // std::shared_ptr<std::shared_ptr<Trapeze<double>>[]> trapezes = std::make_shared<std::shared_ptr<Trapeze<double>>[]>(n);
    // for (size_t i = 0; i < n; i++) {
    //     trapezes[i] = std::make_shared<Trapeze<double>>(4);
    //     std::cin >> *(trapezes[i]);
    // }
    // Array<Trapeze<double>> arr = Array<Trapeze<double>>{2, trapezes};
    // arr.print_array_figures_characteristics();
    // arr.print_array_area_sum();
    // return 0;
    // std::unique_ptr<Point<double>[]> point = std::make_unique<Point<double>[]>(4);
    // point[0] = Point<double>{1,1}; point[1] = Point<double>{3,5}; point[2] = Point<double>{7,5}; point[3] = Point<double>{9,1};
    // Trapeze<double> trap1(4, std::move(point));
    // double x,y = 0;
    // trap1.found_center().get_point(x, y);
    // if (x == 5 && y == 3){
    //     std::cout << "true";
    // }
    // return 0;
// }