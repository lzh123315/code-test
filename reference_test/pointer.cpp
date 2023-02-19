#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;
class A{
    int a;
public:
    const int* getA(){
        return &a;
    }
    A(int tmp){
        a = tmp;
    }
    void modifyA(int tmp){
        a = tmp;
    }
};

int main(){
    A a1{3};
    std::vector<const int*> vec;
    vec.push_back(a1.getA());
}