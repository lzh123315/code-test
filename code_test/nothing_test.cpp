#include <iostream>
#include <typeinfo>
#include <array>
#include <eigen3/Eigen/Core>
#include <optional>
#include <vector>

using optVec = std::vector<std::optional<int>>;

int main(){
    optVec vec(6);
    vec.clear();
    vec.resize(6);
    for (int i = 0; i < 6; ++i){
        vec[i] = i;
    }
}