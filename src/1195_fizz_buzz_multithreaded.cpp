#include "1195_fizz_buzz_multithreaded.h"

namespace _1195 {

    FizzBuzz::FizzBuzz(int n) : n(n) {};

    void FizzBuzz::fizz(std::function<void()> printFizz) {
        run([this]() { return index % 3 == 0 && index % 5 != 0; },
            [&]() { printFizz(); output << "fizz"; });
    }

    void FizzBuzz::buzz(std::function<void()> printBuzz) {
        run([this]() { return index % 3 != 0 && index % 5 == 0; },
            [&]() { printBuzz(); output << "buzz"; });
    }

    void FizzBuzz::fizzbuzz(std::function<void()> printFizzBuzz) {
        run([this]() { return index % 3 == 0 && index % 5 == 0; },
            [&]() { printFizzBuzz(); output << "fizzbuzz"; });
    }

    void FizzBuzz::number(std::function<void(int)> printNumber) {
        run([this]() { return index % 3 != 0 && index % 5 != 0; },
            [&]() { printNumber(index); output << std::to_string(index); });
    }

    void FizzBuzz::run(std::function<bool()> condition, std::function<void()> action) {
        while (true) {
            std::unique_lock<std::mutex> lock(mx);
            cv.wait(lock, [&]() { return index > n || condition(); });
            if (index > n) break;
            action();
            index++;
            cv.notify_all();
        }
    }

    std::string FizzBuzz::getOutput() {
        return output.str();
    }

}