cmake_minimum_required(VERSION 3.30)

project(NODAM C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_OSX_ARCHITECTURES arm64)

# Find Python3
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

# Include Python headers
include_directories(${Python3_INCLUDE_DIRS})

# Add executable
add_executable(NODAM test.c)

# Link Python library
target_link_libraries(NODAM ${Python3_LIBRARIES})

