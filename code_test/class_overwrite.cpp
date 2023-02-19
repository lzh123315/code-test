#include <iostream>

class base
{
public:
    void testa()
    {
        std::cout << 3.1415 << std::endl;
    }

    void test()
    {
        testa();
    }
};

class A : public base
{
public:
    void testa()
    {
        std::cout << 3 << std::endl;
    }
};

int main()
{
    base a;
    a.test();
    A a1;
    a1.test();
}