#include <vector>
#include <iostream>

struct test
{
    int a;
    float b;
};

int main()
{
    std::vector<test> a;
    a.emplace_back(test{1, 3.0});
}