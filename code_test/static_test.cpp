#include <thread>
#include <chrono>
#include <iostream>

class Single
{
public:
    int x_ = 0;

    Single(int x) : x_(x)
    {
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    void print() const
    {
        std::cout << "thread id:" << std::this_thread::get_id() << " x:" << x_ << std::endl;
    }

    static Single &instance()
    {
        static Single instan(100);
        return instan;
    }
};

void test_func()
{
    Single::instance().print();
}

int main()
{
    const auto time1 = std::chrono::steady_clock::now();
    std::thread t1(test_func);
    std::thread t2(test_func);

    t1.join();
    t2.join();
    const auto time2 = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(time2 - time1).count() << std::endl;
}