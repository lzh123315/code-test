#include <iostream>
#include <queue>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

using CallbackFunc = void *(void *);
struct Task
{
    CallbackFunc func;
    void *arg;
};

class ThreadPool
{
    std::queue<Task> taskQueue_;
    size_t qCapacity_;

    std::vector<std::thread> threads_;
    std::thread manageThread_;

    int minNum_;
    int maxNum_;
    int busyNum_;
    int liveNum_;
    int exitNum_;

    std::mutex mutexPool_;
    std::mutex mutexBusyNum_;
    std::condition_variable notEmpty_;
    std::condition_variable notFull_;
    void work();

public:
    ThreadPool(int minNum, int maxNum, size_t qCap);
    void addTask(CallbackFunc callback, void *arg);
};
