#include "380_insert_delete_get_random_O_1.h"

namespace _380 {

    /*
    * Store elements in a vector for O(1) random access, and maintain an unordered_map to track each element's index for O(1) lookup/delete.
    * On removal, swap the target element with the last one to avoid shifting — then pop_back.
    * 
    * Time complexity:
    * O(1)
    * 
    * Space complexity:
    * O(N)
    */
    RandomizedSet::RandomizedSet() : rng(std::random_device{}()) {}

    bool RandomizedSet::insert(int val) {
        if (contains(val)) {
            return false;
        }

        elems.push_back(val);
        val_to_index[val] = elems.size() - 1;

        return true;
    }

    bool RandomizedSet::remove(int val) {
        if (!contains(val)) {
            return false;
        }

        int index = val_to_index[val];
        int last_elem = elems.back();

        elems[index] = last_elem;
        val_to_index.erase(val);

        if (last_elem != val) {
            val_to_index[last_elem] = index;
        }

        elems.pop_back();

        return true;
    }

    int RandomizedSet::getRandom() {
        if (elems.empty()) {
            throw std::runtime_error("Vector is empty");
        }

        std::uniform_int_distribution<int> dist(0, elems.size() - 1);
        return elems[dist(rng)];
    }

    bool RandomizedSet::contains(int val) {
        return val_to_index.count(val) > 0;
    }

}