#include <iostream>
#include <vector>
#include <optional>

using namespace std;

class A{
public:
    vector<int> a;
    A(){
        a = {0, 0};
        std::cout  << "defualt construct func!" << std::endl;
    }
    A(const vector<int>& tmp) : a(tmp){
        std::cout << "param construct func!" << std::endl;
    }
    ~A(){
        std::cout << "deconstruct func!" << std::endl;
    } 
};

std::optional<A> test(bool flag){
    std::optional<A> a;
    a.value() = A({1, 2, 3});
    if (!flag) return {};
    return a;
}

int main(){
    test(true);
    std::cout << "false:" << std::endl;
    test(false);
}
