#include "1117_building_H2O.h"

namespace _1117 {

    /*
    * Use a single mutex, one condition variable, and a shared counter count_hydrogen to synchronize hydrogen and oxygen threads.
    * 
    * Hydrogen threads wait until count_hydrogen < 2, then increment the counter, release hydrogen, and notify all waiting threads.
    * Oxygen threads wait until exactly count_hydrogen == 2, then release oxygen, reset the counter to 0, and notify all waiting threads.
    * 
    * All state changes happen under the lock, so there are no data races.
    * 
    * Time complexity:
    * O(1)
    * 
    * Space complexity:
    * O(1)
    */
    void H2O::hydrogen(std::function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(mtx_);
        cv_.wait(lock, [this] { return count_hydrogen_ < 2; });

        //while (count_hydrogen_ == 2) { // the same as above
        //    cv_.wait(lock);
        //}

        count_hydrogen_++;

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        output_ += 'H';

        cv_.notify_all();
    }

    void H2O::oxygen(std::function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(mtx_);
        // Wait until exactly 2 hydrogens are available
        cv_.wait(lock, [this] { return count_hydrogen_ == 2; });

        //while (count_hydrogen_ < 2) { // the same
        //    cv_.wait(lock);
        //}

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();

        output_ += 'O';

        count_hydrogen_ = 0;
 
        cv_.notify_all();
    }

    std::string H2O::getOutput() {
        return output_;
    }

}