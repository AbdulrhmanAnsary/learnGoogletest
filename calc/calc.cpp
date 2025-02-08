#include <stdexcept>

int divide(int numerator, int denominator) {
  if (denominator == 0)
    throw std::invalid_argument("Division by zero");

  return numerator / denominator;
}

int sum(int x, int y) { return x + y; }

int sub(int x, int y) { return x - y; }
