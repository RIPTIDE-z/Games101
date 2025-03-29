cmake_minimum_required (VERSION 3.10)
project (Transformation)

include_directories("../Eigen/include")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable (Transformation main.cpp)