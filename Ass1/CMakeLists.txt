cmake_minimum_required(VERSION 3.10)
project(Rasterizer1)


# windows
include_directories( "../Eigen/include")
list(APPEND CMAKE_PREFIX_PATH "../OpenCV-mingw/x64/mingw/lib")
# list(APPEND CMAKE_PREFIX_PATH "../OpenCV-msvc/x64/vc17/lib")

# linux
# include_directories(/usr/local/include)

find_package(OpenCV REQUIRED)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(Rasterizer1 main.cpp rasterizer.hpp rasterizer.cpp Triangle.hpp Triangle.cpp)
target_link_libraries(Rasterizer1 ${OpenCV_LIBRARIES})