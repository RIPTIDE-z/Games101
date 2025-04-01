cmake_minimum_required (VERSION 3.10)
project (Transformation)

# windows
include_directories("../Eigen/include")

# linux
# find_package(Eigen3 REQUIRED)
# include_directories(EIGEN3_INCLUDE_DIR)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable (Transformation main.cpp)
add_executable(Extra extra.cpp)