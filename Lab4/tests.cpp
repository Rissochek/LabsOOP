#include <iostream>
#include <cstddef>
#include "lib/Figure.h"
#include "googletest/googletest/include/gtest/gtest.h"

TEST(Compare, BaseCase) {
    std::unique_ptr<Point<int>[]> point = std::make_unique<Point<int>[]>(4);
    point[0] = Point<int>{1,1}; point[1] = Point<int>{3,5}; point[2] = Point<int>{7,5}; point[3] = Point<int>{9,1};
    Trapeze<int> trap1(4, std::move(point));
    Trapeze<int> trap2(4, std::move(point));
    ASSERT_TRUE(trap1 == trap2);
}

TEST(Compare, DifferentOrder) {
    std::unique_ptr<Point<int>[]> point = std::make_unique<Point<int>[]>(4);
    point[0] = Point<int>{1,1}; point[1] = Point<int>{3,5}; point[2] = Point<int>{7,5}; point[3] = Point<int>{9,1};
    std::unique_ptr<Point<int>[]> point2 = std::make_unique<Point<int>[]>(4);
    point2[0] = Point<int>{1,1}; point2[1] = Point<int>{7,5}; point2[2] = Point<int>{3,5}; point2[3] = Point<int>{9,1};
    Trapeze<int> trap1(4, std::move(point));
    Trapeze<int> trap2(4, std::move(point2));
    ASSERT_TRUE(trap1 == trap2);
}

TEST(Compare, DifferentPoints) {
    std::unique_ptr<Point<int>[]> point = std::make_unique<Point<int>[]>(4);
    point[0] = Point<int>{1,1}; point[1] = Point<int>{3,5}; point[2] = Point<int>{7,5}; point[3] = Point<int>{9,1};
    std::unique_ptr<Point<int>[]> point2 = std::make_unique<Point<int>[]>(4);
    point2[0] = Point<int>{1,1}; point2[1] = Point<int>{0,5}; point2[2] = Point<int>{7,5}; point2[3] = Point<int>{9,1};
    Trapeze<int> trap1(4, std::move(point));
    Trapeze<int> trap2(4, std::move(point2));
    ASSERT_FALSE(trap1 == trap2);
}

TEST(AreaCalc, BaseCase) {
    std::unique_ptr<Point<int>[]> point = std::make_unique<Point<int>[]>(4);
    point[0] = Point<int>{1,1}; point[1] = Point<int>{3,5}; point[2] = Point<int>{7,5}; point[3] = Point<int>{9,1};
    Trapeze<int> trap1(4, std::move(point));
    ASSERT_EQ(double(trap1), 24.0);
}

TEST(AreaCalc, TotalArea) {
    const size_t n = 3;
    std::shared_ptr<std::shared_ptr<Figure<double>>[]> figures = std::make_shared<std::shared_ptr<Figure<double>>[]>(n);
    std::unique_ptr<Point<double>[]> point = std::make_unique<Point<double>[]>(4);
    point[0] = Point<double>{1,1}; point[1] = Point<double>{3,5}; point[2] = Point<double>{7,5}; point[3] = Point<double>{9,1};
    figures[0] = std::make_shared<Trapeze<double>>(4,std::move(point));
    figures[1] = std::make_shared<Trapeze<double>>(4, std::move(point));
    figures[2] = std::make_shared<Trapeze<double>>(4, std::move(point));
    Array<Figure<double>> arr = Array<Figure<double>>{3, figures};
    ASSERT_EQ(arr.get_array_area_sum(), 72);
}

TEST(CenterCalc, BaseCase) {
    std::unique_ptr<Point<double>[]> point = std::make_unique<Point<double>[]>(4);
    point[0] = Point<double>{1,1}; point[1] = Point<double>{3,5}; point[2] = Point<double>{7,5}; point[3] = Point<double>{9,1};
    Trapeze<double> trap1(4, std::move(point));
    double x,y = 0;
    trap1.found_center().get_point(x, y);
    ASSERT_EQ(x, 5);
    ASSERT_EQ(y, 3);
}
