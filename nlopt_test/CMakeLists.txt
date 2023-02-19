cmake_minimum_required(VERSION 3.0.2)
project(multi_racecar_jps)


find_package(Eigen3 REQUIRED)
find_package(NLopt REQUIRED)

include_directories(
    SYSTEM
    ${EIGEN3_INCLUDE_DIR}
    ${NLopt_INCLUDE_DIRS} 
)

set(CMAKE_CXX_STANDARD 17)


add_executable (norm_test 
    norm_test.cpp)
target_link_libraries(norm_test nlopt mgl)

