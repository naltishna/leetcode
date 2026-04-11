/*
https://leetcode.com/problems/print-foobar-alternately/description/

1115. Print FooBar Alternately

Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}

The same instance of FooBar will be passed to two different threads:

thread A will call foo(), while
thread B will call bar().
Modify the given program to output "foobar" n times.

Example 1:
Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
"foobar" is being output 1 time.

Example 2:
Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.

Constraints:
1 <= n <= 1000
*/

#pragma once

#include <functional>
#include <mutex>

namespace _1115 {

    class FooBar {
    private:
        std::mutex mtx;
        std::condition_variable cv;
        std::string output = "";
        int switcher = 0;
        int n;

    public:
        FooBar(int n);

        void foo(std::function<void()> printFoo);

        void bar(std::function<void()> printBar);

        std::string getOutput();
    };

}