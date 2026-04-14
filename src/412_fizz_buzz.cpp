#include "412_fizz_buzz.h"

namespace _412 {

    /*
    * Single pass from 1 to n, classifying each number via divisibility checks (% 15, % 3, % 5)
    * in order to handle FizzBuzz case first, then going through to Fizz, Buzz, or number.
    * 
    * Time complexity:
    * O(n)
    * 
    * Space complexity:
    * O(n)
    */
    std::vector<std::string> Solution::fizzBuzz(int n) {
        std::vector<std::string> result;
        result.reserve(n);

        for (int index = 1; index <= n; ++index) {
            if (index % 15 == 0)     result.push_back("FizzBuzz");
            else if (index % 3 == 0) result.push_back("Fizz");
            else if (index % 5 == 0) result.push_back("Buzz");
            else                     result.push_back(std::to_string(index));
        }

        return result;
    }

}