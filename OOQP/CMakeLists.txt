cmake_minimum_required(VERSION 2.8.9)

project(astar)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include 
                    maps
                    "/home/lzh/third_party/OOQP/include"
)

link_directories("/home/lzh/third_party/OOQP/lib")

add_executable(main example.cpp)

target_link_libraries(main 
                    ooqpgensparse
                    ooqpsparse
                    ooqpgondzio
                    ooqpbase 
                    blas 
                    ma27 
                    gfortran
)