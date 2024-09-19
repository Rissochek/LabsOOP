#include <iostream>
#include "googletest/googletest/include/gtest/gtest.h"

int count_vowels_from_string(std::string input_string);

TEST(Tests_should_complete, All_vowels_test) {
  ASSERT_EQ(count_vowels_from_string("aoeui"), 5);
  std::cout << "|aoeui| contains 5 vowel symbols" << std::endl; 
}

TEST(Tests_should_complete, Without_vowels_test) {
  ASSERT_EQ(count_vowels_from_string("dhfjdhjfnmxncm"), 0);
  std::cout << "|dhfjdhjfnmxncm| contains 0 vowel symbols" << std::endl; 
}

TEST(Tests_should_complete, Empty_string) {
  ASSERT_EQ(count_vowels_from_string(""), 0);
  std::cout << "|| contains 0 vowel symbols" << std::endl; 
}

TEST(Tests_should_complete, String_with_only_whitespaces) {
  ASSERT_EQ(count_vowels_from_string("  "), 0);
  std::cout << "|  | contains 0 vowel symbols" << std::endl; 
}

TEST(Tests_should_complete, String_with_wrong_symbol) {
  ASSERT_EQ(count_vowels_from_string("☹"), 0);
  std::cout << "|☹| contains 0 vowel symbols" << std::endl; 
}

TEST(Tests_should_complete, Vowels_and_consonants) {
  ASSERT_EQ(count_vowels_from_string("afjkuio"), 4);
  std::cout << "|afjkuio| contains 4 vowel symbols" << std::endl; 
}

TEST(Tests_should_complete, Vowels_and_consonants_with_whitespace) {
  ASSERT_EQ(count_vowels_from_string("afjkuio aofjki"), 7);
  std::cout << "|afjkuio aofjki| contains 7 vowel symbols" << std::endl; 
}

TEST(Tests_should_complete, Capital_vowels) {
  ASSERT_EQ(count_vowels_from_string("AfjkuiO aofjki fdjkOd"), 8);
  std::cout << "|AfjkuiO aofjki fdjkOd| contains 8 vowel symbols" << std::endl; 
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}