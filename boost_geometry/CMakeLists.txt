cmake_minimum_required(VERSION 3.0.2)
project(boost_geometry_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O1")


include_directories(
    ${catkin_INCLUDE_DIRS} 
)


add_executable(boost_geometry_test
    boost_geometry_test.cpp
)

target_link_libraries(boost_geometry_test 
    ${catkin_LIBRARIES}
)
