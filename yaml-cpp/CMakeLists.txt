cmake_minimum_required(VERSION 3.0.2)
project(yaml-test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")


#YAML
find_package(yaml-cpp REQUIRED)
include_directories(${YAML_CPP_INCLUDE_DIR})


add_executable(main main.cpp)
target_link_libraries(main yaml-cpp)

