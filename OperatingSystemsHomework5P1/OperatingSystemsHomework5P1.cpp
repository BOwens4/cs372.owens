// This program creates a latch class with 4 specified methods
// Braden Owens
// 3/7/2023
// Operating Systems


#include <iostream>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <thread>
using namespace std;
class latch 
{
public:
    explicit latch(size_t count) : counter(count) {}

    void count_down(unsigned int amtToDecrement)
    {
        counter -= amtToDecrement;
        unique_lock<mutex> lock(mutex1);
        if (counter == 0) 
        {
            c.notify_all();
        }
    }
    void wait()
    {
        unique_lock<mutex> lock(mutex1);
        c.wait(lock, [this]() { return counter == 0; });
    }
    bool try_wait()
    {
        unique_lock<mutex> lock(mutex1);
        return counter == 0;
    }

    void arrive_and_wait()
    {
        counter --;
        unique_lock<mutex> lock(mutex1);
        if (counter == 0) 
        {
            c.notify_all();
        }
        else {
            c.wait(lock, [this]() { return counter == 0; });
        }

    }
private:

    size_t counter;
    condition_variable c;
    mutex mutex1;
};

int main()
{
    // test code
    vector<thread>t;
    latch latch1(2);
    for (int count = 0; count < 2; count++)
    {
        t.emplace_back([&latch1]()
            {
                latch1.count_down(1);
            });
    }
    latch1.wait();
    for (int count = 0; count < 2; count++)
    {
        t.join();
    }
   




}
//https://www.tutorialspoint.com/cpp_standard_library/cpp_vector_emplace_back.htm#:~:text=The%20C%2B%2B%20function%20std%3A%3A,increases%20container%20size%20by%20one.
//https://en.cppreference.com/w/cpp/thread/latch/count_down
//https://en.cppreference.com/w/cpp/thread/latch/arrive_and_wait
//https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3666.html
