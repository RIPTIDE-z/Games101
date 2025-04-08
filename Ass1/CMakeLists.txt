cmake_minimum_required(VERSION 3.10)
project(Rasterizer1)

# windows
include_directories( "${EIGEN}/include")
list(APPEND CMAKE_PREFIX_PATH "${OPENCV}/x64/vc17/lib")

# linux
# include_directories(/usr/local/include)

find_package(OpenCV REQUIRED)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(Rasterizer1 main.cpp rasterizer.hpp rasterizer.cpp Triangle.hpp Triangle.cpp)
target_link_libraries(Rasterizer1 ${OpenCV_LIBRARIES})