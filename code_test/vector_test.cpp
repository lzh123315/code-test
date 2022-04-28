#include <vector>
#include <cstring>
#include <cstdlib>
#include <chrono>
#include <iostream>
 
//complie command : g++ -std=c++11 -o0 vector_test.cpp 

const size_t TEST_ITERATIONS = 10;
const size_t TEST_ARRAY_SIZE = 100000;
 
int main(int argc, char** argv) {
 
    std::vector<bool> v2(TEST_ARRAY_SIZE, false);
    std::vector<bool> v3(TEST_ARRAY_SIZE, false);
    std::vector<bool> v4(TEST_ARRAY_SIZE, false);
  
    auto t3 = std::chrono::steady_clock::now();
    for(size_t i = 0; i < TEST_ITERATIONS; ++i) {
        std::fill(v2.begin(), v2.end(), true);
    }
    auto t4 = std::chrono::steady_clock::now();
    std::cout << "std::fill cost time:" << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
    std::cout << std::endl;

    auto t5 = std::chrono::steady_clock::now();
    for(size_t i = 0; i < TEST_ITERATIONS; ++i) {
        for (std::vector<bool>::iterator it=v3.begin(), end=v3.end(); it!=end; ++it) {
            *it = true;
        }
    }
    auto t6 = std::chrono::steady_clock::now();
    std::cout << "(for it) cost time:" << std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count();
    std::cout << std::endl;
    
    auto t7 = std::chrono::steady_clock::now();
    for(size_t i = 0; i < TEST_ITERATIONS; ++i) {
        v4.assign(v4.size(), true);
    }
    auto t8 = std::chrono::steady_clock::now();
    std::cout << "(assign) cost time:" << std::chrono::duration_cast<std::chrono::microseconds>(t8 - t7).count();
    std::cout << std::endl;


    return EXIT_SUCCESS;
}
