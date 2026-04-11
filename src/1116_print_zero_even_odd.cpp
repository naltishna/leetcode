#include "1116_print_zero_even_odd.h"

#include <algorithm>
#include <string>

namespace _1116 {

    /*
    * Three threads coordinate via a shared state variable (0 → zero's turn, 1 → odd's turn, 2 → even's turn).
    * Each thread blocks on cv.wait() until the state matches its role, then prints, updates state, and notifies others.
    * This creates a strict interleaved execution: 0 → odd/even → 0 → odd/even → ...
    * 
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(1)
    */
    ZeroEvenOdd::ZeroEvenOdd(int num) : n(num) {}
    
    // printNumber(x) outputs "x", where x is an integer.
    void ZeroEvenOdd::zero(std::function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            std::unique_lock<std::mutex> lock(mx);
            cv.wait(lock, [this] { return state == 0; });

            output += '0';

            printNumber(0);
            state = (current_number % 2 != 0) ? 1 : 2;

            cv.notify_all();
        }
    }

    void ZeroEvenOdd::even(std::function<void(int)> printNumber) {
        for (int i = 0; i < n / 2; ++i) {
            std::unique_lock<std::mutex> lock(mx);
            cv.wait(lock, [this] { return state == 2; });

            output += std::to_string(current_number);

            printNumber(current_number);
            current_number++;
            state = 0;

            cv.notify_all();
        }
    }

    void ZeroEvenOdd::odd(std::function<void(int)> printNumber) {
        for (int i = 0; i < (n + 1) / 2; ++i) {
            std::unique_lock<std::mutex> lock(mx);
            cv.wait(lock, [this] { return state == 1; });

            output += std::to_string(current_number);

            printNumber(current_number);
            current_number++;
            state = 0;

            cv.notify_all();
        }
    }

    std::string ZeroEvenOdd::getOutput() {
        return output;
    }

}