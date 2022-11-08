cmake_minimum_required(VERSION 3.10)
project(Actividad_4_2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL2 REQUIRED)
include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})

find_package(CGAL REQUIRED)

add_executable(exec main.cpp)

target_link_libraries(exec CGAL::CGAL ${SDL2_LIBRARIES})