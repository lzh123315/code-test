cmake_minimum_required (VERSION 3.10)

project(ceres_test)

set(CXX_STANDARD 17)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

find_package(OpenCV REQUIRED)
include_directories(${OPENCV_INCLUDE_DIRS})

add_executable(basic_test basic_test.cpp)
target_link_libraries(basic_test ${CERES_LIBRARIES} ${OpenCV_LIBS})

add_executable(non_linear non_linear_opt.cpp)
target_link_libraries(non_linear ${CERES_LIBRARIES} ${OpenCV_LIBS})
