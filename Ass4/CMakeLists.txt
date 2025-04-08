cmake_minimum_required(VERSION 3.10)
project(BezierCurve)

# When using Linux, just comment out this line
list(APPEND CMAKE_PREFIX_PATH "${OPENCV}/x64/vc17/lib")

find_package(OpenCV REQUIRED)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(BezierCurve main.cpp)
target_link_libraries(BezierCurve ${OpenCV_LIBRARIES})