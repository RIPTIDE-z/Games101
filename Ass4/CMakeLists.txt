cmake_minimum_required(VERSION 3.10)
project(BezierCurve)

list(APPEND CMAKE_PREFIX_PATH "../OpenCV-mingw/x64/mingw/lib")
find_package(OpenCV REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)

add_executable(BezierCurve main.cpp)

target_link_libraries(BezierCurve ${OpenCV_LIBRARIES})
