#include <iostream>
#include <vector>

using namespace std;

class A{
public:
    const vector<int>& a;
    A(const vector<int>& tmp) : a(tmp){
        std::cout << "param construct func!" << std::endl;
    }
    ~A(){
        std::cout << "deconstruct func!" << std::endl;
    } 
};


int main(){
    vector<int> b{6};
    A a(b);
    std::cout << "b:" << b[0] << "a:" << a.a[0] << std::endl;
    b.clear();
    b.resize(1);
    std::cout << "a:" << b[0] << "b:" << a.a[0] << std::endl;
}