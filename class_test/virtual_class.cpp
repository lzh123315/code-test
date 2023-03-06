#include <iostream>

class Base
{
public:
    Base(int x) : a(x){};

protected:
    int a;
};

class A : public Base
{
public:
    using Base::Base;

private:
    int b;
};

int main()
{

    A a(1);
    return 0;
}