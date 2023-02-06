#include <memory>
#include <iostream>

namespace sdef{

template <typename T>
class unique_ptr{
private:
    T* ptr_;

public:
    unique_ptr() : ptr_(nullptr){}
    unique_ptr(T* ptr): ptr_(ptr){}

    unique_ptr(const unique_ptr& other) = delete;
    unique_ptr& operator= (const unique_ptr& other) = delete;

    unique_ptr(unique_ptr&& other) noexcept{
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }
    unique_ptr& operator= (unique_ptr&& other) noexcept{
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;

        return *this;
    }

    T* operator->() const{
        return ptr_;
    }

    T* get(){
        return ptr_;
    }

    ~unique_ptr(){
        if (ptr_ != nullptr){
            delete ptr_;
            ptr_ = nullptr;
        }
    }
};
} // namespace sdef

class A{
public:
    int a = 5;

};

int main(){
    sdef::unique_ptr a = new A();
    sdef::unique_ptr b = std::move(a);
}

