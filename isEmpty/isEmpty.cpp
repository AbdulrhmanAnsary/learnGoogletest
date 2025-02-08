#include <gtest/gtest.h>

bool isEmpty(bool result = true) {
	return result;
}

TEST(isEmptyTest, isEmptyCorrectCase) {
	ASSERT_TRUE(isEmpty());
	std::cout << "=======After ASSERT_TRUE=======\n";
  EXPECT_TRUE(isEmpty());
}

TEST(isEmptyTest, isEmptyWrongCase) {
	ASSERT_TRUE(isEmpty(false));
	std::cout << "=======After ASSERT_TRUE=======\n";
  EXPECT_TRUE(isEmpty());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
