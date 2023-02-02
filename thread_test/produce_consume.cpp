#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <iostream>

template <typename T, int N>
class SyncQueue
{
public:
    SyncQueue() : max_size_(N){};

    void produce(T data)
    {
        std::unique_lock<std::mutex> lock(mutex_);
        cond_not_full_.wait(lock, [this]()
                            { return data_.size() != N; });
        std::cout << data << "is producing" << std::endl;
        data_.push(data);
        cond_not_empty_.notify_one();
    }

    int consume()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        cond_not_empty_.wait(lock, [this]()
                             { return !data_.empty(); });
        int res = data_.front();
        std::cout << res << "is consuming" << std::endl;
        data_.pop();
        cond_not_full_.notify_one();
        return res;
    }

private:
    std::queue<T> data_;
    std::mutex mutex_;
    std::condition_variable cond_not_empty_;
    std::condition_variable cond_not_full_;
    size_t max_size_;
};

template <typename T, int N>
void produceFunc(SyncQueue<T, N> &queue, int num)
{
    for (int i = 0; i < num; ++i)
    {
        queue.produce(T{});
    }
}

template <typename T, int N>
void consumingFunc(SyncQueue<T, N> &queue, int num)
{
    for (int i = 0; i < num; ++i)
    {
        auto res = queue.consume();
    }
}

int main()
{
    SyncQueue<int, 3> sync_queue;

    std::thread t1(produceFunc<int, 3>, std::ref(sync_queue), 5);
    std::thread t2(consumingFunc<int, 3>, std::ref(sync_queue), 5);

    t1.join();
    t2.join();
}