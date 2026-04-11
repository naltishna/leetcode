#include "1115_print_foobar_alternately.h"

namespace _1115 {

    /*
    * Use a shared state flag (switcher) to enforce strict foo → bar → foo ordering between two threads.
    * Each thread waits until the flag signals its turn, prints, then flips the flag and signals the other.
    * 
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(1)
    */
    FooBar::FooBar(int n) {
        this->n = n;
    }

    void FooBar::foo(std::function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() {return switcher == 0; });

            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();

            output += "foo";
            switcher = 1;

            cv.notify_all();
        }
    }

    void FooBar::bar(std::function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() { return switcher == 1; });

            // printBar() outputs "bar". Do not change or remove this line.
            printBar();

            output += "bar";
            switcher = 0;

            cv.notify_all();
        }
    }

    std::string FooBar::getOutput() {
        return output;
    }

}