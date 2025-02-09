# Learn Google Test

Welcome to the **Learn Google Test** repository! This project teaches you how to write unit tests for C++ code using Google Test (GTest), Google's powerful testing framework.

## Table of Contents
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Building and Running Tests](#building-and-running-tests)
  - [Recommended Method (CMake)](#recommended-method-cmake)
  - [Manual Installation (Advanced Users)](#manual-installation-advanced-users)
- [Example Test](#example-test)
- [Contributing](#contributing)
- [License](#license)

## Prerequisites
- C++ compiler (GCC, Clang, or MSVC)
- [CMake](https://cmake.org/) (version 3.14+)
- Git (for cloning the repository)
- Google Test dependencies (for manual installation):
  ```bash
  sudo apt-get install libgtest-dev  # Ubuntu/Debian
  ```

## Installation

### Clone the Repository
```bash
git clone https://github.com/AbdulrhmanAnsary/learnGoogletest.git
cd learnGoogletest
```

## Building and Running Tests

### Recommended Method (CMake)

1. **Create a build directory** (outside source tree):
```bash
mkdir -p build && cd build
```

2. **Generate build files** with CMake:
```bash
cmake .. -DCMAKE_BUILD_TYPE=Release
```

3. **Compile the project**:
```bash
make -j$(nproc)
```

4. **Run the test executable**:
```bash
./bin/example_test  # Adjust path if different
```

Example `CMakeLists.txt` for reference:
```cmake
cmake_minimum_required(VERSION 3.14)
project(LearnGTest)

find_package(GTest REQUIRED)
add_executable(example_test src/example_test.cpp)
target_link_libraries(example_test GTest::GTest GTest::Main)
```

---

### Manual Installation (Advanced Users)

#### 1. Build Google Test Libraries
```bash
cd googletest
mkdir build && cd build
cmake .. -DBUILD_SHARED_LIBS=ON
make -j$(nproc)
```

#### 2. Install System-Wide
```bash
# Install libraries
sudo cp lib/*.so /usr/local/lib/

# Install headers
sudo cp -r ../googletest/include/gtest /usr/local/include

# Update library cache
sudo ldconfig -v
```

**⚠️ Critical Warnings:**
- Verify library compatibility with your system
- Backup existing GTest installations
- Consider using virtual environments instead

---

## Example Test
```cpp
#include <gtest/gtest.h>

TEST(MathTest, BasicMultiplication) {
  ASSERT_EQ(6 * 7, 42) << "Multiplication logic broken";
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
```

## Contributing
Contributions welcome! Please:
1. Fork & create a feature branch
2. Include documentation updates
3. Test changes thoroughly
4. Submit PR with [conventional commits](https://www.conventionalcommits.org/)

## License
MIT License - See [LICENSE](LICENSE).
Official documentation: [Google Test Docs](https://google.github.io/googletest/)
