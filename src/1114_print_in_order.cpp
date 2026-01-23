#include "1114_print_in_order.h"

namespace _1114_cv {

    /*
    * The Producer-Consumer Synchronization Pattern using a Shared State Variable (state_),
    * a single condition variable (cv_) and the wait/notify mechanism is used to ensure in
    * the strict sequential execution of methods (first -> second -> third) across multiple threads.
    *
    * Time complexity:
    * O(1)
    *
    * Space complexity:
    * O(1)
    */
    void Foo::first(std::function<void()> printFirst) {
        std::unique_lock<std::mutex> lock(mtx_);
        cv_.wait(lock, [&] { return state_ == 0; });

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        state_ = 1;
        output += "first";
        cv_.notify_one();
    }

    void Foo::second(std::function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(mtx_);
        cv_.wait(lock, [this] {return state_ == 1; });

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        state_ = 2;
        output += "second";
        cv_.notify_one();
    }

    void Foo::third(std::function<void()> printThird) {
        std::unique_lock<std::mutex> lock(mtx_);
        cv_.wait(lock, [this] { return state_ == 2; });

        // printThird() outputs "third". Do not change or remove this line.
        printThird();

        output += "third";
    }

    std::string Foo::getOutput() {
        return output;
    }

}

namespace _1114_atomic {

    /*
    * Busy Waiting (or Polling) approach combined with Atomic Operations and Memory Ordering.
    *
    * The std::memory_order_release ensures that all memory writes that happened before this store
    * (including the output of printFirst() and the update to state_) become visible to any thread
    * that subsequently performs an acquire load on the same atomic variable.
    * 
    * The std::memory_order_acquire ensures that all memory writes that happened before the corresponding 
    * release operation in the signaling thread are visible to the current thread after the load operation succeeds.
    * This makes sure that when the thread proceeds past the while loop, it sees the effects of the previous step (like printFirst() finishing).
    * 
    * Time complexity:
    * O(1)
    * 
    * Theoretically it is possible that a thread is wait for multiple times if the first thread takes a long time before writing a new value.
    * Therefore, the worst-case time complexity of the second method depends on the rate of change of the first thread's state and is estimated as O(n), 
    * where n is the number of loop iterations. The total time complexity of all methods in such case is O(1) + O(n) + O(m),
    * where m and n depend on the thread holding and the number of condition checks.
    * 
    * Space complexity:
    * O(1)
    */
    void Foo::first(std::function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        output += "first";

        state_.store(1, std::memory_order_release);
    }

    void Foo::second(std::function<void()> printSecond) {
        while (state_.load(std::memory_order_acquire) < 1) {
            std::this_thread::yield();
        }

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        output += "second";
        state_.store(2, std::memory_order_release);
    }

    void Foo::third(std::function<void()> printThird) {
        while (state_.load(std::memory_order_acquire) < 2) {
            std::this_thread::yield();
        }

        // printThird() outputs "third". Do not change or remove this line.
        printThird();

        output += "third";
    }

    std::string Foo::getOutput() {
        return output;
    }

}