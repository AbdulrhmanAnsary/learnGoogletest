#include <gmock/gmock.h>
#include <gtest/gtest.h>

// Interface that represents the e-mail service
class IEmailService {
public:
  virtual void sendEmail(const std::string &to, const std::string &message) = 0;
  virtual ~IEmailService() = default;
};

// A mock object that represents the e-mail service
class MockEmailService : public IEmailService {
public:
  MOCK_METHOD(void, sendEmail,
              (const std::string &to, const std::string &message), (override));
};

// The function that uses the email service
void notifyUser(IEmailService *emailService, const std::string &userEmail) {
  emailService->sendEmail(userEmail, "You have a new notification!");
}

// code test
TEST(EmailServiceTest, SendsNotification) {
  // Arrange
  MockEmailService mockService;
  EXPECT_CALL(mockService,
              sendEmail("user@example.com", "You have a new notification!"))
      .Times(1); // We expect this function to be called once.

  // Act
  notifyUser(&mockService, "user@example.com");

	// Assert: No additional tests needed because we have already checked out forecast in EXPECT_CALL
}
