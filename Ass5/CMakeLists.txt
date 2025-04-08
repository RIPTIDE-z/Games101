cmake_minimum_required(VERSION 3.10)
project(RayTracing1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(RayTracing1 main.cpp Object.hpp Vector.hpp Sphere.hpp global.hpp Triangle.hpp Scene.cpp Scene.hpp Light.hpp Renderer.cpp)
#target_compile_options(RayTracing1 PUBLIC -Wall -Wextra -pedantic -Wshadow -Wreturn-type)
# target_compile_options(RayTracing1 PUBLIC -Wall -Wextra -pedantic -Wshadow -Wreturn-type -fsanitize=undefined)
#target_compile_features(RayTracing1 PUBLIC cxx_std_17)
# target_link_libraries(RayTracing1 PUBLIC -fsanitize=undefined)