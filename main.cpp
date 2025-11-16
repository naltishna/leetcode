// leetcode.cpp : Defines the entry point for the application.
//

#include <iostream>

#include "helper.h"
#include "utils.h"

#include "2_add_two_numbers.h"
#include "18_4sum.h"
#include "23_merge_k_sorted_lists.h"
#include "56_merge_intervals.h"
#include "120_triangle.h"
#include "136_single_number.h"
#include "374_guess_number_higher_or_lower.h"
#include "704_binary_search.h"

using namespace std;

int main()
{
    //////////////////////
#if 1
    /**
     * 2. Add Two Numbers
     */
    {
        ListNode* l1_1 = ListNodeHelper::createList({ 2, 4, 3 });
        ListNode* l1_2 = ListNodeHelper::createList({ 5, 6, 4 });
        _2::Solution s{};
        ListNode* temp = s.addTwoNumbers(l1_1, l1_2);
        my_assert("708" == ListNodeHelper::convertListNodeToString(temp));
        ListNodeHelper::freeList(l1_1);
        ListNodeHelper::freeList(l1_2);
        ListNodeHelper::freeList(temp);

        ListNode* l2_1 = ListNodeHelper::createList({ 0 });
        ListNode* l2_2 = ListNodeHelper::createList({ 0 });
        temp = s.addTwoNumbers(l2_1, l2_2);
        my_assert("0" == ListNodeHelper::convertListNodeToString(temp));
        ListNodeHelper::freeList(l2_1);
        ListNodeHelper::freeList(l2_2);
        ListNodeHelper::freeList(temp);

        ListNode* l3_1 = ListNodeHelper::createList({ 9,9,9,9,9,9,9 });
        ListNode* l3_2 = ListNodeHelper::createList({ 9,9,9,9 });
        temp = s.addTwoNumbers(l3_1, l3_2);
        my_assert("89990001" == ListNodeHelper::convertListNodeToString(temp));
        ListNodeHelper::freeList(l3_1);
        ListNodeHelper::freeList(l3_2);
        ListNodeHelper::freeList(temp);
    }
#endif
    //////////////////////
#if 1
    /**
     * 18. 4Sum
     */
    {
        std::vector<int> l0{ 1, 0, -1 };
        std::vector<int> l1{ 1, 0, -1, 0, -2, 2 }; // Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
        std::vector<int> l2{ 2, 2, 2, 2, 2 };
        std::vector<int> l3{ -3, -2, -1, 0, 0, 1, 2, 3 }; // Output: {[-3, -2, 2, 3], [-3, -1, 1, 3], [-3, 0, 0, 3], [-3, 0, 1, 2], [-2, -1, 0, 3], [-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]}
        std::vector<int> l4{ 1000000000, 1000000000, 1000000000, 1000000000 };
        std::vector<int> l5{ -2, -1, -1, 1, 1, 2, 2 };

        _18::Solution s;
        my_assert(0 == s.fourSum(l0, 0).size());
        my_assert(3 == s.fourSum(l1, 0).size());
        my_assert(1 == s.fourSum(l2, 8).size());
        my_assert(8 == s.fourSum(l3, 0).size());
        my_assert(0 == s.fourSum(l4, 0).size());
        my_assert(2 == s.fourSum(l5, 0).size());
    }
#endif
    //////////////////////
#if 1
    /**
     * 23. Merge k Sorted Lists algorithm
     */
    {
        ListNode* l1_1 = new ListNode(1, new ListNode(4, new ListNode(5)));
        ListNode* l1_2 = new ListNode(1, new ListNode(3, new ListNode(4)));
        ListNode* l1_3 = new ListNode(2, new ListNode(6));

        // [[1,4,5],[1,3,4],[2,6]]
        std::vector<ListNode*> lists1 = { l1_1, l1_2, l1_3 };
        // []
        std::vector<ListNode*> lists2;
        // [[]]
        std::vector<ListNode*> lists3 = { nullptr };

        {
            auto start_time = get_current_time();
            _23_recursion::Solution s{};
            ListNode* result = s.mergeKLists(lists1);
            ListNodeHelper::printList(result);
            ListNodeHelper::freeList(result);
            auto end_time = get_current_time();
            print_elapsed_time(start_time, end_time, "_23_recursion_ver");

            result = s.mergeKLists(lists2);
            ListNodeHelper::freeList(result);

            result = s.mergeKLists(lists3);
            ListNodeHelper::freeList(result);
        }

        // priority_queue ver
        std::vector<int> data1{ 1, 4, 5 };
        std::vector<int> data2{ 1, 3, 4 };
        std::vector<int> data3 = { 2, 6 };

        ListNode* list1 = ListNodeHelper::createList(data1);
        ListNode* list2 = ListNodeHelper::createList(data2);
        ListNode* list3 = ListNodeHelper::createList(data3);

        // [[1,4,5],[1,3,4],[2,6]]
        std::vector<ListNode*> vecs = { list1, list2, list3 };

        {
            auto start_time = get_current_time();
            _23_priority_queue::Solution s{};
            ListNode* result = s.mergeKLists(vecs);
            ListNodeHelper::printList(result);
            ListNodeHelper::freeList(result);
            auto end_time = get_current_time();
            print_elapsed_time(start_time, end_time, "_23_priority_queue_ver");

            // []
            std::vector<ListNode*> empty_lists;
            result = s.mergeKLists(empty_lists);
            ListNodeHelper::freeList(result);

            // [[]]
            std::vector<ListNode*> single_empty_list = { nullptr };
            result = s.mergeKLists(single_empty_list);
            ListNodeHelper::freeList(result);
        }
    }
#endif
    //////////////////////
#if 1
    /**
     * 56. Merge Intervals
     */
    {
        std::vector<std::vector<int>> l0_in{ {1, 3}, {2, 6}, {8, 10}, {15, 18} };
        std::vector<std::vector<int>> l1_in{ {1, 4}, {4, 5} };
        std::vector<std::vector<int>> l2_in{ {4, 7}, {1, 4} };

        _56::Solution s{};
        std::vector<std::vector<int>> case1 = s.merge(l0_in); //Output: { {1, 6}, {8, 10}, {15, 18} }
        my_assert(3 == case1.size());
        std::vector<std::vector<int>> case2 = s.merge(l1_in); //Output: { {1, 5} }
        my_assert(1 == case2.size());
        std::vector<std::vector<int>> case3 = s.merge(l2_in); //Output: { {1, 7} }
        my_assert(1 == case3.size());
    }
#endif
    //////////////////////
#if 1
    /**
     * 120. Triangle
     */
    {
        std::vector<std::vector<int>> l0{ {2},
                                          {3, 4},
                                          {6, 5, 7},
                                          {4, 1, 8, 3} };
        std::vector<std::vector<int>> l1{ {-10} };
        std::vector<std::vector<int>> l2{ {2},
                                          {3, 4},
                                          {6, 5, 2},
                                          {1, 4, 3, 8} };
        std::vector<std::vector<int>> l3{ {-1},
                                          {2, 3},
                                          {1, -1, -3} };
        std::vector<std::vector<int>> l4{ };

        _120::Solution s;
        my_assert(11 == s.minimumTotal(l0));
        my_assert(-10 == s.minimumTotal(l1));
        my_assert(11 == s.minimumTotal(l2));
        my_assert(-1 == s.minimumTotal(l3));
        my_assert(0 == s.minimumTotal(l4));
    }
#endif
    //////////////////////
#if 1
    /**
     * 136. Single Number
     */
    {
        std::vector<int> l1{ 2,2,1 };
        std::vector<int> l2{ 4,1,2,1,2 };
        std::vector<int> l3{ 1 };

        _136::Solution s{};
        my_assert(1 == s.singleNumber(l1));
        my_assert(4 == s.singleNumber(l2));
        my_assert(1 == s.singleNumber(l3));
    }

#endif
    //////////////////////
#if 1
    /**
     * 374. Guess Number Higher or Lower
     */
    {
        _374::Solution s{};
        s.setPick(6);
        my_assert(6 == s.guessNumber(10));
        s.setPick(1);
        my_assert(1 == s.guessNumber(1));
        s.setPick(1);
        my_assert(1 == s.guessNumber(1));
    }
#endif
    //////////////////////
#if 1
    /**
     * 704. Binary Search
     */
    {
        std::vector<int> nums1 = { -1,0,3,5,9,12 };
        std::vector<int> nums2 = { 5 };
        std::vector<int> nums3;

        {
            auto start_time = get_current_time();
            _704_recursion::Solution s{};
            my_assert(4 == s.search(nums1, 9));
            my_assert(5 == s.search({ -1,0,3,5,9,12 }, 12));
            my_assert(2 == s.search({ 2, 5, 7, 9 }, 7));
            my_assert(-1 == s.search(nums1, 2));
            my_assert(0 == s.search(nums2, 5));
            my_assert(0 == s.search({ 5 }, 5));
            my_assert(-1 == s.search(nums3, 5));
            my_assert(-1 == s.search({}, 5));
            auto end_time = get_current_time();
            print_elapsed_time(start_time, end_time, "_704_recursion_ver");
        }

        {
            auto start_time = get_current_time();
            _704_STL::Solution s{};
            my_assert(4 == s.search(nums1, 9));
            my_assert(5 == s.search({ -1,0,3,5,9,12 }, 12));
            my_assert(2 == s.search({ 2, 5, 7, 9 }, 7));
            my_assert(-1 == s.search(nums1, 2));
            my_assert(0 == s.search(nums2, 5));
            my_assert(0 == s.search({ 5 }, 5));
            my_assert(-1 == s.search(nums3, 5));
            my_assert(-1 == s.search({}, 5));
            auto end_time = get_current_time();
            print_elapsed_time(start_time, end_time, "_704_STL_ver");
        }

        {
            auto start_time = get_current_time();
            _704_binary_search::Solution s{};
            my_assert(4 == s.search(nums1, 9));
            my_assert(5 == s.search({ -1,0,3,5,9,12 }, 12));
            my_assert(2 == s.search({ 2, 5, 7, 9 }, 7));
            my_assert(-1 == s.search(nums1, 2));
            my_assert(0 == s.search(nums2, 5));
            my_assert(0 == s.search({ 5 }, 5));
            my_assert(-1 == s.search(nums3, 5));
            my_assert(-1 == s.search({}, 5));
            auto end_time = get_current_time();
            print_elapsed_time(start_time, end_time, "_704_binary_search_ver");
        }

        {
            auto start_time = get_current_time();
            _704_linear_search::Solution s{};
            my_assert(4 == s.search(nums1, 9));
            my_assert(5 == s.search({ -1,0,3,5,9,12 }, 12));
            my_assert(2 == s.search({ 2, 5, 7, 9 }, 7));
            my_assert(-1 == s.search(nums1, 2));
            my_assert(0 == s.search(nums2, 5));
            my_assert(0 == s.search({ 5 }, 5));
            my_assert(-1 == s.search(nums3, 5));
            my_assert(-1 == s.search({}, 5));
            auto end_time = get_current_time();
            print_elapsed_time(start_time, end_time, "_704_linear_search_ver");
        }
    }
#endif
    //////////////////////
    return 0;
}
