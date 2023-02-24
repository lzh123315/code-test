#include <iostream>
#include <queue>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <functional>
#include <future>
#include <memory>

class ThreadPool
{
    std::queue<std::function<void()>> taskQueue_;
    size_t maxQCap_;

    std::vector<std::thread> threads_;

    std::mutex mutexPool_;
    std::condition_variable notEmpty_;
    std::condition_variable notFull_;

    bool shutdown = false;

public:
    ThreadPool(size_t size, size_t maxQCap)
    {
        maxQCap_ = maxQCap;
        threads_.reserve(size);

        for (int i = 0; i < size; ++i)
        {
            threads_.emplace_back([this]()
                                  {
    while (1)
    {

        std::unique_lock<std::mutex> lock{mutexPool_};
        notEmpty_.wait(lock, [this]()
                       { return shutdown || !taskQueue_.empty(); });
        if (shutdown)
            return;
        auto task = std::move(taskQueue_.front());
        taskQueue_.pop();
        notFull_.notify_one();
        lock.unlock();

        task();
    } });
        }
    }

    template <class F, class... Args>
    auto addTask(F &&f, Args &&...args) -> std::future<typename std::result_of<F(Args...)>::type>
    {
        using ret_type = typename std::result_of<F(Args...)>::type;
        auto task_ptr = std::make_shared<std::packaged_task<ret_type()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...));
        auto fut = task_ptr->get_future();

        std::unique_lock<std::mutex>
            lock{mutexPool_};
        notFull_.wait(lock, [this]()
                      { return shutdown || taskQueue_.size() != maxQCap_; });
        if (shutdown)
        {
            throw std::runtime_error("Thread Pool is shutdown! Do not add task!");
        }
        taskQueue_.emplace([task_ptr]
                           { (*task_ptr)(); });
        notEmpty_.notify_one();
        return fut;
    }

    ~ThreadPool()
    {
        {
            std::lock_guard<std::mutex> lock{mutexPool_};
            shutdown = true;
        }

        notEmpty_.notify_all();
        for (auto &&thread : threads_)
        {
            thread.join();
        }
    }
};
