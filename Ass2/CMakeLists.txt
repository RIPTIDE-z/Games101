cmake_minimum_required(VERSION 3.10)
project(Rasterizer2)

# windows
include_directories("../Eigen/include")
list(APPEND CMAKE_PREFIX_PATH "../OpenCV-mingw/x64/mingw/lib")

# linux
# include_directories(/usr/local/include)

find_package(OpenCV REQUIRED)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

add_executable(Rasterizer2 main.cpp rasterizer.hpp rasterizer.cpp global.hpp Triangle.hpp Triangle.cpp)
target_link_libraries(Rasterizer2 ${OpenCV_LIBRARIES})