cmake_minimum_required(VERSION 3.0.2)
project(osqp_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

set(OSQP_INCLUDE_DIRS "/usr/local/include/osqp")

find_package(OsqpEigen REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(
    ${OSQP_INCLUDE_DIRS}
    ${Eigen3_INCLUDE_DIRS} 
)

add_executable(main main.cpp)
target_link_libraries(main osqp OsqpEigen)
