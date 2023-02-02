cmake_minimum_required (VERSION 3.5)

project(ipopt_test)

set(CXX_STANDARD 17)
set(sources test.cpp)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable(ipopt_test ${sources})

target_link_libraries(ipopt_test ipopt)
