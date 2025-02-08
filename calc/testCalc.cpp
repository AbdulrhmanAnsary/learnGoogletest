#include "calc.hpp"      // Ensure that there is a sum and sub function
#include <gmock/gmock.h> // If you want to used google mock
#include <gtest/gtest.h>

TEST(divisionTest, correctDivide) {
	EXPECT_EQ(5, divide(10, 2));
}

TEST(divisionTest, wrongDivide) {
  EXPECT_NE(1, divide(10, 20));
}

TEST(divisionTest, throwsExceptionOnDivideByZero) {
  EXPECT_THROW(divide(10, 0), std::invalid_argument); // We expect that the function will throw an exception from the type std::invalid_argument
}

// Test case for sum function
TEST(sumTest, correctSum) {
  // sumFunc: test suite name
  // test1: test name

  // Testing pattern: Arrange-Act-Assert (AAA)

  // Arrange & Act
  int result = sum(2, 3);

  // Assert
  EXPECT_EQ(5, result);
}

TEST(sumTest, wrongSum) { EXPECT_NE(5, sum(12, 3)); }

// Test case for sub function
TEST(subtractTest, correctSubtract) { EXPECT_EQ(-1, sub(2, 3)); }

TEST(subtractTest, wrongSubtract) { EXPECT_NE(15, sub(12, 3)); }

// You can delete Main() from TestCalc.cpp if you link to -lgtest_main when compiling
int main() {
  // Initialize all test cases below main and put them in a queue
  ::testing::InitGoogleTest();

  // Run all test cases below main
  return RUN_ALL_TESTS();
}

// How to run code:
// clang++ calc.cpp testCalc.cpp -o testCalc -lgtest -lgtest_main -pthread
