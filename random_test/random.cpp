#include <iostream>
#include <random>
#include <cmath>

int main()
{
    std::random_device r;
    std::mt19937 gen(r());
    std::uniform_int_distribution<> distr(1, 100);
    for (int i = 0; i < 10; ++i)
    {
        std::cout << distr(gen) << std::endl;
    }
    std::cout << std::tan(3.14 / 2) << std::endl;
}