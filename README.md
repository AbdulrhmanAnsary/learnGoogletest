# Learn Google Test

Welcome to the **Learn Google Test** repository! This project aims to help you master writing unit tests for C++ code using Google Test (GTest), a robust testing framework developed by Google.

## Table of Contents
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Getting Started](#getting-started)
- [Example Test](#example-test)
- [Building and Running Tests](#building-and-running-tests)
- [Contributing](#contributing)
- [License](#license)

## Prerequisites
- C++ compiler (e.g., GCC, Clang, MSVC)
- [CMake](https://cmake.org/) (version 3.14+)
- Git (for cloning the repository)
- Google Test library (installation instructions below)

## Installation

### Clone the Repository
```bash
git clone https://github.com/AbdulrhmanAnsary/learnGoogletest.git
cd learnGoogletest
```

### Install Google Test
#### Linux/macOS
Use your package manager:
```bash
# Ubuntu/Debian
sudo apt-get install libgtest-dev

# macOS (via Homebrew)
brew install googletest
```

#### Windows
- Use [vcpkg](https://vcpkg.io/): `vcpkg install gtest`
- Or follow the [official guide](https://github.com/google/googletest).

## Getting Started

1. **Create a Test File**: Write tests in a `_test.cpp` file (e.g., `example_test.cpp`).
2. **Include Headers**: 
   ```cpp
   #include <gtest/gtest.h>
   ```
3. **Write Tests**: Use `TEST()` and assertion macros like `ASSERT_EQ` or `EXPECT_TRUE`.

## Example Test
```cpp
// example_test.cpp
#include <gtest/gtest.h>

TEST(MathTest, Addition) {
  EXPECT_EQ(2 + 3, 5);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
```

## Building and Running Tests

### Using CMake
1. Create a `CMakeLists.txt`:
   ```cmake
   cmake_minimum_required(VERSION 3.14)
   project(LearnGTest)
   
   find_package(GTest REQUIRED)
   add_executable(example_test example_test.cpp)
   target_link_libraries(example_test GTest::GTest GTest::Main)
   ```
2. Build and run:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ./example_test
   ```

### Manual Compilation (Quick Start)
```bash
g++ -std=c++11 example_test.cpp -lgtest -lgtest_main -pthread -o example_test
./example_test
```

## Contributing
Contributions are welcome! Please:
1. Fork the repository.
2. Create a feature branch.
3. Submit a pull request with a clear description.

## License
This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

---

For more details, refer to the [Google Test Documentation](https://github.com/google/googletest).
```