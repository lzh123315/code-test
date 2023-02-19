#include <iostream>
#include <queue>
#include <thread>
#include <vector>
#include <mutex>

using CallbackFunc = void *(void *);
struct Task
{
    CallbackFunc func;
    void *arg;
};

class ThreadPool
{
    std::queue<Task> taskQueue_;
    std::vector<std::thread> threads_;

    int minNum_;
    int maxNum_;
    int busyNum_;
    int liveNum_;
    int exitNum_;

    std::mutex mutexPool_;
    static void work(void *arg);
};
