cmake_minimum_required (VERSION 3.10)
project (Transformation)

# windows
include_directories( "${EIGEN}/include")

# linux
# find_package(Eigen3 REQUIRED)
# include_directories(EIGEN3_INCLUDE_DIR)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable (Transformation main.cpp)
add_executable(Extra extra.cpp)