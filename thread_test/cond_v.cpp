#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

bool flag = true;
int a = 5;

std::condition_variable cond;
std::mutex mutex;

int main()
{

    std::thread t1([]()
                   { for (int i = 0; i < 100000000; ++i){

                   }
                   std::cout << "flag set true" << std::endl;
                   flag = true; 
                   cond.notify_one(); });

    std::unique_lock<std::mutex>
        lock(mutex);
    cond.wait(lock, []()
              { return flag; });

    t1.join();
}