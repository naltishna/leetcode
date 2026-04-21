#include "1226_the_dining_philosophers.h"

#include <iostream>
#include <syncstream>

namespace _1226 {

    /*
    * A limit mutex acts as a gatekeeper — only one philosopher at a time can attempt to pick up forks.
    * Once both forks are locked, limit is released so the next philosopher can try concurrently.
    * Forks are indexed by philosopher id, preventing circular wait.
    * 
    * No deadlock — circular wait broken by limit serializing fork acquisition.
    * 
    * Concurrency: up to 2 philosophers eat simultaneously (non-adjacent ones), but fork-grabbing is still sequential.
    * 
    * Starvation: possible — limit is not fair, a philosopher could keep losing the race.
    * 
    * Time complexity:
    * O(1)
    * 
    * Space complexity:
    * O(1)
    */
    void DiningPhilosophers::wantsToEat(int philosopher,
                                        std::function<void()> pickLeftFork,
                                        std::function<void()> pickRightFork,
                                        std::function<void()> eat,
                                        std::function<void()> putLeftFork,
                                        std::function<void()> putRightFork) {
        int leftFork = philosopher;
        int rightFork = (philosopher + 1) % 5;
        std::osyncstream(std::cout) << "left: " << leftFork << ", right: " << rightFork << std::endl;

        std::unique_lock<std::mutex> lock(limit);
        std::lock_guard<std::mutex> l_fork(forks[leftFork]);
        std::lock_guard<std::mutex> r_fork(forks[rightFork]);
        lock.unlock();

        pickRightFork();
        pickLeftFork();
        eat();
        putLeftFork();
        putRightFork();
    }

}