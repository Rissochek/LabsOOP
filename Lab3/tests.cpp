#include <iostream>
#include <cstddef>
#include "lib/Figure.h"
#include "googletest/googletest/include/gtest/gtest.h"

TEST(Compare, BaseCase) {
    Point *arr = new Point[4];
    arr[0] = Point{1,1};arr[1] = Point{3,5};arr[2] = Point{7,5};arr[3] = Point{9,1};
    Trapeze trap1(4, arr);
    Trapeze trap2(4, arr);
    ASSERT_TRUE(trap1 == trap2);
}

TEST(Compare, DifferentOrder) {
    Point *arr = new Point[4];
    arr[0] = Point{1,1};arr[1] = Point{3,5};arr[2] = Point{7,5};arr[3] = Point{9,1};
    Point *arr2 = new Point[4];
    arr2[0] = Point{1,1};arr2[1] = Point{7,5};arr2[2] = Point{3,5};arr2[3] = Point{9,1};
    Trapeze trap1(4, arr);
    Trapeze trap2(4, arr2);
    ASSERT_TRUE(trap1 == trap2);
}

TEST(Compare, DifferentPoints) {
    Point *arr = new Point[4];
    arr[0] = Point{1,1};arr[1] = Point{3,5};arr[2] = Point{7,5};arr[3] = Point{9,1};
    Point *arr2 = new Point[4];
    arr2[0] = Point{1,1};arr2[1] = Point{0,5};arr2[2] = Point{7,5};arr2[3] = Point{9,1};
    Trapeze trap1(4, arr);
    Trapeze trap2(4, arr2);
    ASSERT_FALSE(trap1 == trap2);
}

TEST(AreaCalc, BaseCase) {
    Point *arr = new Point[4];
    arr[0] = Point{1,1};arr[1] = Point{3,5};arr[2] = Point{7,5};arr[3] = Point{9,1};
    Trapeze trap1(4, arr);
    ASSERT_EQ(double(trap1), 24.0);
}

TEST(AreaCalc, TotalArea) {
    const size_t n = 3;
    double total_area = 0;
    Figure** figures = new Figure*[n];
    Point *arr = new Point[4];
    arr[0] = Point{1,1};arr[1] = Point{3,5};arr[2] = Point{7,5};arr[3] = Point{9,1};
    figures[0] = new Trapeze(4, arr);
    figures[1] = new Trapeze(4, arr);
    figures[2] = new Trapeze(4, arr);
    for(size_t i = 0; i < n; i++){
        total_area += double(*figures[i]);
    }
    ASSERT_EQ(total_area, 72);
}

TEST(CenterCalc, BaseCase) {
    Point center = {5, 3};
    Point *arr = new Point[4];
    arr[0] = Point{1,1};arr[1] = Point{3,5};arr[2] = Point{7,5};arr[3] = Point{9,1};
    Trapeze trap1(4, arr);
    ASSERT_EQ(trap1.found_center().x, center.x);
    ASSERT_EQ(trap1.found_center().y, center.y);
}
