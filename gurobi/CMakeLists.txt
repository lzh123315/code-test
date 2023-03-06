cmake_minimum_required(VERSION 3.0.2)
project(gurubi_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

set(GUROBI_DIR $ENV{GUROBI_HOME}/share/)
message(${GUROBI_DIR})
find_package(GUROBI CONFIG REQUIRED)

include_directories(
  ${GUROBI_INCLUDE_DIRS}
)

add_executable(qcp qcp.cpp)
target_link_libraries(qcp 
  ${GUROBI_LIBRARIES}
)

add_executable(dense dense_c++.cpp)
target_link_libraries(dense
  ${GUROBI_LIBRARIES}
)
