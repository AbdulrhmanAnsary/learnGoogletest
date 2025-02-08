#include <gtest/gtest.h>
#include "database.hpp"

// Example of Test Fixture
class DatabaseTest : public ::testing::Test {
protected:
	Database db;

protected:
  // Setting up the database
  void SetUp() override {
    // database initialization code
    db.addData(1, 25);
    db.addData(2, 30);
  }

  // Clean the database
  void TearDown() override {
    // database cleaning code
    
  }
};

// test using TEST FIXTURE
// Add data test
TEST_F(DatabaseTest, AddData) {
	// databaseTest: test_fixture
	// addData: test_name
	// We are testing the addition of data to the database here

	db.addData(3, 40);
	EXPECT_EQ(db.getData(3), 40);
}

// Test not to change the values when you add with the same key
TEST_F(DatabaseTest, OverwriteData) {
	db.addData(1, 35);
	EXPECT_EQ(db.getData(1), 35);
}

// Get valid data test
TEST_F(DatabaseTest, GetDataValid) {
	EXPECT_EQ(db.getData(1), 25);
  EXPECT_EQ(db.getData(2), 30);
}

// Test for obtaining data that does not exist
TEST_F(DatabaseTest, GetDataInvalid) {
	EXPECT_EQ(db.getData(100), -1);
}
