#include <set>
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>

constexpr int num = 2500;

int main(){
    std::random_device rd;
    std::mt19937 gen(rd());

    std::set<int> s;
    std::uniform_int_distribution<> dist(1, 10000);
    for (int i = 0; i < num; ++i){
        s.insert(dist(gen));
    }
    std::vector<int> a;
    a.reserve(num / 10);
    for (int i = 0; i < num / 10; ++i){
        a.push_back(dist(gen));
    }

    auto t1 = std::chrono::steady_clock::now();
    for (auto n : a){
        auto it = s.lower_bound(n);
    }
    auto t2 = std::chrono::steady_clock::now();
    std::cout << "set lower_bound cost time:" << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << std::endl;

    auto t3 = std::chrono::steady_clock::now();
    for (auto n : a){
        auto it = std::lower_bound(s.begin(), s.end(), n);
    }
    auto t4 = std::chrono::steady_clock::now();
    std::cout << "set lower_bound cost time:" << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
    std::cout << std::endl;
    
}