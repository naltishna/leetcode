#include "1279_traffic_light_controlled_intersection.h"

namespace _1279 {

    /*
    * Each car acquires a lock, switches the light if needed, then crosses.
    * Only one car crosses at a time, fully sequential — no parallelism even for same-road cars (potential bottleneck under high load).
    * No race conditions, no starvation risk.
    *
    * Time complexity:
    * O(1)
    *
    * Space complexity:
    * O(1)
    */
    void TrafficLight::carArrived(int carId, int roadId, int direction, std::function<void()> turnGreen, std::function<void()> crossCar) { 
        std::lock_guard<std::mutex> lock(mtx);

        if (roadId != road) {
            turnGreen();
            road = roadId;
        }

        crossCar();
    }

}