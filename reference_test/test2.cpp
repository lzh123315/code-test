#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;
class A{
    int a;
public:
    const int& getA(){
        return a;
    }
    A(int tmp){
        a = tmp;
    }
    void modifyA(int tmp){
        a = tmp;
    }
};

int main(){
    std::unordered_map<int, const int&> map;
    A a1{2}, a2{3}, a3{6};
    map.insert({1, a1.getA()});
    map.insert({2, a2.getA()});
    map.insert({3, a3.getA()});
    const auto& g1 = map.at(1);
    const auto& g2 = map.at(2);
    const auto& g3 = map.at(3);
    cout << g1 << " " << g2 << " " << g3 << std::endl;
    a1.modifyA(6);
    a2.modifyA(8);
    a3.modifyA(10);
    cout << "modify" << endl;
    cout << g1 << " " << g2 << " " << g3 << std::endl;
}