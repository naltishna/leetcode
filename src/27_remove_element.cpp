#include "27_remove_element.h"

namespace _27 {

    /*
    * Erase-remove idiom.
    * 
    * std::remove_if performs a single, linear (O(n)) pass to shift the desired elements to the start, returning an iterator that marks the new logical end.
    * std::erase deletes the elements from that boundary onward, freeing the space.
    * 
    * - Time complexity:
    * O(n)
    *
    * - Space complexity:
    * O(1)
    */
    template<>
    int Solution<_27_v1>::removeElement(std::vector<int>& nums, int val) {
        nums.erase(std::remove_if(nums.begin(), nums.end(), [val](int x) { return x == val; }), nums.end());
        return nums.size();
    }

    /*
    * std::find() scans the entire vector until the first match is found. The execution time for a single search operation is O(n), where n is the size of the vector.
    * std::erase() operation must shift all subsequent elements to the left to fill the gap left by the removed element.
    * This operation is also linear O(k), where k is the count of elements after the current one is deleted).
    * 
    * If the target element appears frequently, the total runtime can become quadratic (O(n^2)).
    * In that case, every iteration will require two linear steps: first the search, and then shifting all remaining elements. 
    * 
    * - Time complexity:
    * O(n^2)
    * 
    * - Space complexity:
    * O(1)
    */
    template<>
    int Solution<_27_v2>::removeElement(std::vector<int>& nums, int val) {
        std::vector<int>::iterator it;
        while (true) {
            it = std::find(nums.begin(), nums.end(), val);
            if (it != nums.end()) {
                nums.erase(it);
            }
            else {
                break;
            }
        }

        return nums.size();
    }

}