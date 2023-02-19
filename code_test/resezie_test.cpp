#include <vector>
#include <iostream>

void printVec(const std::vector<int>& vec){
    for (auto it = vec.begin(); it != vec.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> vec(3, 6);
    printVec(vec);
    vec.resize(8);
    printVec(vec);
    return 0;
}