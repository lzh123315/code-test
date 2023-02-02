#include <thread>
#include <iostream>

int main()
{

    {
        std::thread t([]()
                      { std::cout << "hello world"; });
        t.join();
    }
    return 0;
}