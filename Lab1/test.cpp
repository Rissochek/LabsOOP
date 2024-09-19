#include <iostream>
#include "googletest/googletest/include/gtest/gtest.h"

int count_vowels_from_string(std::string input_string);

TEST(First_lab_tests, Subtest_1) {
  ASSERT_EQ(count_vowels_from_string("aoeui"), 5);
  std::cout << "|aoeui| contains 5 vowel symbols" << std::endl; 
}

TEST(First_lab_tests, Subtest_2) {
  ASSERT_EQ(count_vowels_from_string("afjkuio"), 4);
  std::cout << "|afjkuio| contains 4 vowel symbols" << std::endl; 
}

TEST(First_lab_tests, Subtest_3) {
  ASSERT_EQ(count_vowels_from_string("afjkuio aofjki"), 7);
  std::cout << "|afjkuio aofjki| contains 7 vowel symbols" << std::endl; 
}

TEST(First_lab_tests, Subtest_4) {
  ASSERT_EQ(count_vowels_from_string("AfjkuiO aofjki fdjkOd"), 8);
  std::cout << "|AfjkuiO aofjki fdjkOd| contains 8 vowel symbols" << std::endl; 
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}