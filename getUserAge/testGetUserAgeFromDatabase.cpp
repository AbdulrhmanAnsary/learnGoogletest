// The goal of using Google Mock in this code is to simulate the database without the need for actual connection to a database.
// This allows us to focus on testing the database-dependent function,
// making sure that the system is running as expected without the need to test the actual base code.

#include <gmock/gmock.h>
#include <gtest/gtest.h>

// Interface that represents a database
class IDatabase {
public:
  virtual int getUserAge(int userId) = 0;
  virtual ~IDatabase() = default;
};

// mock object (mock) for the database
class MockDatabase : public IDatabase {
public:
	// Mock getUserAge
  MOCK_METHOD(int, getUserAge, (int userId), (override));
};

// a function that uses the database
int getUserAgeFromDatabase(IDatabase *db, int userId) {
  return db->getUserAge(userId);
}

// test using gmock
TEST(DatabaseTest, ReturnsCorrectAge) {
	//Test pattern: Arrange-act-Assart (AAA)

  // Arrange
  MockDatabase mockDb;

  // EXPECT_CALL: Preparing the fake behavior of the function
  // WillOnce: Determine what should happen in the first call of this fake function,
  // If getUserAge(42) is called, 25 will be returned
  EXPECT_CALL(mockDb, getUserAge(42)).WillOnce(::testing::Return(25));

  // Act
  int age = getUserAgeFromDatabase(&mockDb, 42);

  // Assert
  EXPECT_EQ(age, 25);
}
