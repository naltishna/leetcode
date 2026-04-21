#include "134_gas_station.h"
#include "class_version.h"

namespace _134 {

    /*
    * Time complexity:
    * O(N^2)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<ver1>::canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int n = gas.size();
        int tank = 0;
        int start = -1;

        for (int i = 0; i < n; ++i) {
            if (start == -1) {
                tank = gas[i] - cost[i];
                
                if (tank < 0) {
                    continue;
                }

                start = i;
            }
            else {
                tank = tank + gas[i] - cost[i];
                if (tank == 0 && start == i + 1) {
                    break;
                }

                if (start + 1 == n) {
                    return -1;
                }
            }

            if (i + 1 == n) {
                i = -1;
            }
        }

        return start;
    }

    /*
    * Track two accumulators: total_tank (global sum) and current_tank (local running sum from candidate start).
    * Whenever current_tank drops below 0 — every station up to i is a dead start, so reset and try i+1.
    * At the end: if total_tank >= 0 a solution is guaranteed to exist, and start_index is it.
    * 
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<ver2>::canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int n = gas.size();
        int total_tank = 0;
        int current_tank = 0;
        int start_index = 0;

        for (int i = 0; i < n; ++i) {
            int net_gas = gas[i] - cost[i];
            total_tank += net_gas;
            current_tank += net_gas;

            if (current_tank < 0) {
                start_index = i + 1;
                current_tank = 0;
            }
        }

        return (total_tank >= 0) ? start_index : -1;
    }

}