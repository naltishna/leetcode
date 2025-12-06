// main.cpp : Defines the entry point for the application.

#include <iostream>
#include <memory>

#include "data.h"
#include "list_node_helpers.h"
#include "utils.h"

#include "2_add_two_numbers.h"
#include "11_container_with_most_water.h"
#include "18_4sum.h"
#include "23_merge_k_sorted_lists.h"
#include "56_merge_intervals.h"
#include "110_balanced_binary_tree.h"
#include "120_triangle.h"
#include "121_best_time_to_buy_and_sell_stock.h"
#include "136_single_number.h"
#include "309_best_time_to_buy_and_sell_stock_with_cooldown.h"
#include "347_top_k_frequent_elements.h"
#include "373_find_k_pairs_with_smallest_sums.h"
#include "374_guess_number_higher_or_lower.h"
#include "480_sliding_window_median.h"
#include "653_two_sum_IV_input_is_a_BST.h"
#include "692_top_k_frequent_words.h"
#include "704_binary_search.h"
#include "763_partition_labels.h"

int main()
{
    //////////////////////
    /**
     * 2. Add Two Numbers
     */
#if 1
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
    /**
     * 11. Container With Most Water
     */
#if 1
    {
        _11::Solution s{};
        std::vector<int> height_1{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
        my_assert(49 == s.maxArea(height_1));
        std::vector<int> height_2{ 1, 1 };
        my_assert(1 == s.maxArea(height_2));
    }
#endif
    //////////////////////
    /**
     * 18. 4Sum
     */
#if 1
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
    /**
     * 23. Merge k Sorted Lists algorithm
     */
#if 1
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

        { // recursion ver
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

        std::vector<int> data1{ 1, 4, 5 };
        std::vector<int> data2{ 1, 3, 4 };
        std::vector<int> data3 = { 2, 6 };

        ListNode* list1 = ListNodeHelper::createList(data1);
        ListNode* list2 = ListNodeHelper::createList(data2);
        ListNode* list3 = ListNodeHelper::createList(data3);

        // [[1,4,5],[1,3,4],[2,6]]
        std::vector<ListNode*> vecs = { list1, list2, list3 };

        { // priority_queue ver
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
    /**
     * 56. Merge Intervals
     */
#if 1
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
    /**
     * 110. Balanced Binary Tree
     */
#if 1
    {
        // [3,9,20,null,null,15,7]
        RawPointer::TreeNode* tn1 = new RawPointer::TreeNode(3, new RawPointer::TreeNode(9, nullptr, nullptr),
            new RawPointer::TreeNode(20, new RawPointer::TreeNode(15, nullptr, nullptr),
                new RawPointer::TreeNode(7, nullptr, nullptr)));
        // [1,2,2,3,3,null,null,4,4]
        RawPointer::TreeNode* tn2 = new RawPointer::TreeNode(1, new RawPointer::TreeNode(2, nullptr, nullptr),
            new RawPointer::TreeNode(2, new RawPointer::TreeNode(3, nullptr, nullptr),
                new RawPointer::TreeNode(3, new RawPointer::TreeNode(4, nullptr, nullptr),
                    new RawPointer::TreeNode(4, nullptr, nullptr))));
        // []
        RawPointer::TreeNode* tn3 = nullptr;

        _110::Solution s{};
        my_assert(true == s.isBalanced(tn1));
        s.destroy(tn1);
        my_assert(false == s.isBalanced(tn2));
        s.destroy(tn2);
        my_assert(true == s.isBalanced(tn3));
        s.destroy(tn3);
    }
#endif
    //////////////////////
    /**
     * 120. Triangle
     */
#if 1
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

        _120::Solution s{};
        my_assert(11 == s.minimumTotal(l0));
        my_assert(-10 == s.minimumTotal(l1));
        my_assert(11 == s.minimumTotal(l2));
        my_assert(-1 == s.minimumTotal(l3));
        my_assert(0 == s.minimumTotal(l4));
    }
#endif
    //////////////////////
    /**
     * 121. Best Time to Buy and Sell Stock
     */
#if 1
    {
        _121::Solution s{};
        std::vector<int> prices_1{ 7, 1, 5, 3, 6, 4 };
        my_assert(5 == s.maxProfit(prices_1));
        std::vector<int> prices_2{ 7, 6, 4, 3, 1 };
        my_assert(0 == s.maxProfit(prices_2));
        std::vector<int> prices_3{ 1, 2 };
        my_assert(1 == s.maxProfit(prices_3));
        std::vector<int> prices_4{ 2, 9, 1, 7, 4 };
        my_assert(7 == s.maxProfit(prices_4));
        std::vector<int> prices_5{ 2 };
        my_assert(0 == s.maxProfit(prices_5));
    }
#endif
    //////////////////////
    /**
     * 136. Single Number
     */
#if 1
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
    /**
     * 309. Best Time to Buy and Sell Stock with Cooldown
     */
#if 1
    {
        std::vector<int> prices_1{ 1, 2, 3, 0, 2 };
        std::vector<int> prices_2{ 1 };
        std::vector<int> prices_3{ 4, 3, 2, 10, 11, 0, 11 };
        std::vector<int> prices_4{ 6, 1, 3, 2, 4, 7 };

        _309::Solution s{};
        my_assert(3 == s.maxProfit(prices_1));
        my_assert(0 == s.maxProfit(prices_2));
        my_assert(19 == s.maxProfit(prices_3));
        my_assert(6 == s.maxProfit(prices_4));
    }
#endif
    //////////////////////
    /**
     * 347. Top K Frequent Elements
     */
#if 1
    {
        std::vector<int> elements_1 = { 1, 1, 1, 2, 2, 3 };
        int k_1 = 2;
        std::vector<int> elements_2 = { 1 };
        int k_2 = 1;
        std::vector<int> elements_3 = { 1, 2, 1, 2, 1, 2, 3, 1, 3, 2 };
        int k_3 = 2;

        _347::Solution s{};
        my_assert("{1, 2}" == vector_to_string(s.topKFrequent(elements_1, k_1)));
        my_assert("{1}" == vector_to_string(s.topKFrequent(elements_2, k_2)));
        my_assert("{1, 2}" == vector_to_string(s.topKFrequent(elements_3, k_3)));
    }
#endif
    //////////////////////
    /**
     * 373. Find K Pairs with Smallest Sums
     */
#if 1
    {
        std::vector<int> l0_0{ 1, 7, 11 };
        std::vector<int> l0_1{ 2, 4, 6 };
        int k0 = 3;

        std::vector<int> l1_0{ 1, 1, 2 };
        std::vector<int> l1_1{ 1, 2, 3 };
        int k1 = 2;

        std::vector<int> l2_0{ 1, 1, 2 };
        std::vector<int> l2_1{ 1, 2, 3 };
        int k2 = 9;

        std::vector<int> l3_0{ 1, 2, 3, 4, 5, 6 };
        std::vector<int> l3_1{ 3, 5, 7, 9 };
        int k3 = 3;
        {
            _373::Solution<v1> s{};
            my_assert("{{1, 2}, {1, 4}, {1, 6}}" == vectors_to_string(s.kSmallestPairs(l0_0, l0_1, k0)));
            my_assert("{{1, 1}, {1, 1}}" == vectors_to_string(s.kSmallestPairs(l1_0, l1_1, k1)));
            my_assert("{{1, 1}, {1, 1}, {1, 2}, {1, 2}, {2, 1}, {1, 3}, {1, 3}, {2, 2}, {2, 3}}" == vectors_to_string(s.kSmallestPairs(l2_0, l2_1, k2)));
            my_assert("{{1, 3}, {2, 3}, {1, 5}}" == vectors_to_string(s.kSmallestPairs(l3_0, l3_1, k3)));
        }
        {
            _373::Solution<v2> s{};
            my_assert("{{1, 2}, {1, 4}, {1, 6}}" == vectors_to_string(s.kSmallestPairs(l0_0, l0_1, k0)));
            my_assert("{{1, 1}, {1, 1}}" == vectors_to_string(s.kSmallestPairs(l1_0, l1_1, k1)));
            my_assert("{{1, 1}, {1, 1}, {1, 2}, {1, 2}, {2, 1}, {1, 3}, {1, 3}, {2, 2}, {2, 3}}" == vectors_to_string(s.kSmallestPairs(l2_0, l2_1, k2)));
            my_assert("{{1, 3}, {2, 3}, {1, 5}}" == vectors_to_string(s.kSmallestPairs(l3_0, l3_1, k3)));
        }
        {
            _373::Solution<v3> s{};
            my_assert("{{1, 2}, {1, 4}, {1, 6}}" == vectors_to_string(s.kSmallestPairs(l0_0, l0_1, k0)));
            my_assert("{{1, 1}, {1, 1}}" == vectors_to_string(s.kSmallestPairs(l1_0, l1_1, k1)));
            my_assert("{{1, 1}, {1, 1}, {1, 2}, {1, 2}, {2, 1}, {1, 3}, {1, 3}, {2, 2}, {2, 3}}" == vectors_to_string(s.kSmallestPairs(l2_0, l2_1, k2)));
            my_assert("{{1, 3}, {2, 3}, {1, 5}}" == vectors_to_string(s.kSmallestPairs(l3_0, l3_1, k3)));
        }
        //std::cout << vector_to_string(s.kSmallestPairs(ln_n_373, ln_n_373, 10000)); // to check throw std::bad_alloc{};
        //std::cout << vector_to_string(s.kSmallestPairs(ln_n_373_1, ln_n_373_2, 9484)); // to check Time Limit Exceeded
    }
#endif
    //////////////////////
    /**
     * 374. Guess Number Higher or Lower
     */
#if 1
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
    /**
     * 480. Sliding Window Median
     */
#if 1
    {
        std::vector<int> nums_1 = { 1, 3, -1, -3, 5, 3, 6, 7 };
        int k_1 = 3;
        std::vector<int> nums_2 = { 1, 2, 3, 4, 2, 3, 1, 4, 2 };
        int k_2 = 3;
        std::vector<int> nums_3 = { 2147483647, 2147483647 };
        int k_3 = 2;
        std::vector<int> nums_4 = { 1, 4, 2, 3 };
        int k_4 = 4;
        std::vector<int> nums_5 = { -2147483648, -2147483648, 2147483647,
                                    -2147483648, -2147483648, -2147483648,
                                    2147483647, 2147483647, 2147483647,
                                    2147483647, -2147483648, 2147483647, -2147483648 };
        int k_5 = 2;
        std::vector<int> num_6 = { 7, 0, 3, 9, 9, 9, 1, 7, 2, 3 };
        int k_6 = 6;

        {
            _480::Solution<_480_v1> s{};
            auto start_time = get_current_time();
            my_assert("{1.0, -1.0, -1.0, 3.0, 5.0, 6.0}" == vector_to_string(s.medianSlidingWindow(nums_1, k_1)));
            my_assert("{2.0, 3.0, 3.0, 3.0, 2.0, 3.0, 2.0}" == vector_to_string(s.medianSlidingWindow(nums_2, k_2)));
            my_assert("{2147483647.0}" == vector_to_string(s.medianSlidingWindow(nums_3, k_3)));
            my_assert("{2.5}" == vector_to_string(s.medianSlidingWindow(nums_4, k_4)));
            my_assert("{-2147483648.0, -0.5, -0.5, -2147483648.0, -2147483648.0, -0.5, 2147483647.0, 2147483647.0, 2147483647.0, -0.5, -0.5, -0.5}" == vector_to_string(s.medianSlidingWindow(nums_5, k_5)));
            my_assert("{8.0, 6.0, 8.0, 8.0, 5.0}" == vector_to_string(s.medianSlidingWindow(num_6, k_6)));
            auto end_time = get_current_time();
            print_elapsed_time(start_time, end_time, "_480_v1");
        }
        {
            _480::Solution<_480_v2> s{};
            auto start_time = get_current_time();
            my_assert("{1.0, -1.0, -1.0, 3.0, 5.0, 6.0}" == vector_to_string(s.medianSlidingWindow(nums_1, k_1)));
            my_assert("{2.0, 3.0, 3.0, 3.0, 2.0, 3.0, 2.0}" == vector_to_string(s.medianSlidingWindow(nums_2, k_2)));
            my_assert("{2147483647.0}" == vector_to_string(s.medianSlidingWindow(nums_3, k_3)));
            my_assert("{2.5}" == vector_to_string(s.medianSlidingWindow(nums_4, k_4)));
            my_assert("{-2147483648.0, -0.5, -0.5, -2147483648.0, -2147483648.0, -0.5, 2147483647.0, 2147483647.0, 2147483647.0, -0.5, -0.5, -0.5}" == vector_to_string(s.medianSlidingWindow(nums_5, k_5)));
            my_assert("{8.0, 6.0, 8.0, 8.0, 5.0}" == vector_to_string(s.medianSlidingWindow(num_6, k_6)));
            auto end_time = get_current_time();
            print_elapsed_time(start_time, end_time, "_480_v2");
        }
        {
            _480::Solution<_480_v3> s{};
            auto start_time = get_current_time();
            my_assert("{1.0, -1.0, -1.0, 3.0, 5.0, 6.0}" == vector_to_string(s.medianSlidingWindow(nums_1, k_1)));
            my_assert("{2.0, 3.0, 3.0, 3.0, 2.0, 3.0, 2.0}" == vector_to_string(s.medianSlidingWindow(nums_2, k_2)));
            my_assert("{2147483647.0}" == vector_to_string(s.medianSlidingWindow(nums_3, k_3)));
            my_assert("{2.5}" == vector_to_string(s.medianSlidingWindow(nums_4, k_4)));
            my_assert("{-2147483648.0, -0.5, -0.5, -2147483648.0, -2147483648.0, -0.5, 2147483647.0, 2147483647.0, 2147483647.0, -0.5, -0.5, -0.5}" == vector_to_string(s.medianSlidingWindow(nums_5, k_5)));
            my_assert("{8.0, 6.0, 8.0, 8.0, 5.0}" == vector_to_string(s.medianSlidingWindow(num_6, k_6)));
            auto end_time = get_current_time();
            print_elapsed_time(start_time, end_time, "_480_v3");
        }
    }
#endif
    //////////////////////
    /**
     * 653. Two Sum IV - Input is a BST
     */
#if 1
    {
        //root = [5,3,6,2,4,null,7]
        auto tn1 = std::make_unique<SmartPointer::TreeNode>(
            5, 
            std::make_unique<SmartPointer::TreeNode>(
                3, 
                std::make_unique<SmartPointer::TreeNode>(2),
                std::make_unique<SmartPointer::TreeNode>(4)),
            std::make_unique<SmartPointer::TreeNode>(
                6, 
                nullptr, 
                std::make_unique<SmartPointer::TreeNode>(7)));

        // root = [2,1,3]
        auto tn2 = std::make_unique<SmartPointer::TreeNode>(
            2,
            std::make_unique<SmartPointer::TreeNode>(
                1),
            std::make_unique<SmartPointer::TreeNode>(
                3));
 
        {
            _653_BFS::Solution s{};
            my_assert(false == s.findTarget(tn1.get(), 28));
            my_assert(true == s.findTarget(tn1.get(), 9));
            my_assert(true == s.findTarget(tn1.get(), 11));
            my_assert(true == s.findTarget(tn2.get(), 3));
        }
        {
            _653_memory_optimal::Solution s{};
            my_assert(false == s.findTarget(tn1.get(), 28));
            my_assert(true == s.findTarget(tn1.get(), 9));
            my_assert(true == s.findTarget(tn1.get(), 11));
            my_assert(true == s.findTarget(tn2.get(), 3));
        }
    }
#endif
    //////////////////////
    /**
     * 692. Top K Frequent Words
     */
#if 1
    {
        std::vector<std::string> words_1 = { "i", "love", "leetcode", "i", "love", "coding" };
        int k_1 = 2;
        std::vector<std::string> words_2 = { "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
        int k_2 = 4;

        _692::Solution s{};
        my_assert("{i, love}" == vector_to_string(s.topKFrequent(words_1, k_1)));
        my_assert("{the, is, sunny, day}" == vector_to_string(s.topKFrequent(words_2, k_2)));
    }
#endif
    //////////////////////
    /**
     * 704. Binary Search
     */
#if 1
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
    /**
     * 763. Partition Labels
     */
#if 1
    {
        std::string s_1 = "ababcbacadefegdehijhklij";
        std::string s_2 = "eccbbbbdec";
        std::string s_3 = "eeeeeeeeee";
        std::string s_4 = "abcdefgh";
        std::string s_5 = "a";
        std::string s_6 = "eaaaabaaec";

        _763::Solution s{};
        my_assert(3 == (s.partitionLabels(s_1)).size());
        my_assert(1 == (s.partitionLabels(s_2)).size());
        my_assert(1 == (s.partitionLabels(s_3)).size());
        my_assert(8 == (s.partitionLabels(s_4)).size());
        my_assert(1 == (s.partitionLabels(s_5)).size());
        my_assert(2 == (s.partitionLabels(s_6)).size());
    }
#endif
    //////////////////////
    return 0;
}