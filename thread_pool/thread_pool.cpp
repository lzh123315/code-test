#include "thread_pool.hpp"

ThreadPool::ThreadPool(int minNum, int maxNum, size_t qCap) : minNum_(minNum), maxNum_(maxNum), qCapacity_(qCap)
{
    threads_.reserve(maxNum);
    busyNum_ = 0;
    liveNum_ = minNum_;
    exitNum_ = 0;

    for (int i = 0; i < minNum_; ++i)
    {
        threads_.emplace_back(work);
    }
}

void ThreadPool::work()
{
    std::unique_lock<std::mutex> lock{mutexPool_};
    notEmpty_.wait(lock, [this]()
                   { return !taskQueue_.empty(); });
    auto task = taskQueue_.front();
    taskQueue_.pop();
    notFull_.notify_one();
    ++busyNum_;
    lock.unlock();

    std::cout << "thread:" << std::this_thread::get_id() << "begin working" << std::endl;
    task.func(task.arg);

    std::cout << "thread:" << std::this_thread::get_id() << "finish working" << std::endl;
    std::lock_guard<std::mutex> block{mutexBusyNum_};
    --busyNum_;
}

void ThreadPool::addTask(CallbackFunc callback, void *arg)
{
    std::unique_lock<std::mutex> lock{mutexPool_};
    notFull_.wait(lock, [this]()
                  { return taskQueue_.size() != qCapacity_; });
    taskQueue_.emplace(callback, arg);
    notEmpty_.notify_one();
}