#include <iostream>
#include "googletest/googletest/include/gtest/gtest.h"
#include "Twelve_lib/Twelve.h"

TEST(Minus_tests, zero_test_both_positive){
    Twelve first_num = Twelve(20, false);
    Twelve second_num = Twelve(20, false);
    Twelve answer = Twelve(0, false);
    ASSERT_TRUE((first_num.minus(second_num)).eq(answer));
}
TEST(Minus_tests, zero_test_both_negative){
    Twelve first_num = Twelve(20, true);
    Twelve second_num = Twelve(20, true);
    Twelve answer = Twelve(0, false);
    ASSERT_TRUE((first_num.minus(second_num)).eq(answer));
}
TEST(Minus_tests, zero_test_positive_negative){
    Twelve first_num = Twelve(20, true);
    Twelve second_num = Twelve(20, false);
    Twelve answer = Twelve(0, false);
    ASSERT_FALSE((first_num.minus(second_num)).eq(answer));
}
TEST(Plus_tests, zero_test){
    Twelve first_num = Twelve(20, false);
    Twelve second_num = Twelve(20, true);
    Twelve answer = Twelve(0, false);
    ASSERT_TRUE((first_num.plus(second_num)).eq(answer));
}
TEST(Gt_tests, zero_true_zero_false){
    Twelve first_num = Twelve(0, false);
    Twelve second_num = Twelve(0, true);
    ASSERT_FALSE(first_num.gt(second_num));
}
TEST(Gt_tests, same_nums_pos_neg){
    Twelve first_num = Twelve(20, false);
    Twelve second_num = Twelve(20, true);
    ASSERT_TRUE(first_num.gt(second_num));
}
TEST(Gt_tests, same_nums_neg_pos){
    Twelve first_num = Twelve(20, true);
    Twelve second_num = Twelve(20, false);
    ASSERT_FALSE(first_num.gt(second_num));
}
TEST(Eq_tests, zero_true_zero_false){
    Twelve first_num = Twelve(0, false);
    Twelve second_num = Twelve(0, true);
    ASSERT_TRUE(first_num.eq(second_num));
}
TEST(Copy_test, test) {
    Twelve num1 = Twelve(20, true);
    Twelve num2 = Twelve(num1);
    ASSERT_TRUE(num2.eq(num1));
}
