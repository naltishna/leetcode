// main.cpp : Defines the entry point for the application.

#include <algorithm>
#include <array>
#include <iostream>
#include <memory>
#include <thread>

#include "data.h"
#include "list_node_helpers.h"
#include "utils.h"
#include "class_version.h"

#include "1_two_sum.h"
#include "2_add_two_numbers.h"
#include "6_zigzag_conversion.h"
#include "9_palindrome_number.h"
#include "11_container_with_most_water.h"
#include "12_integer_to_roman.h"
#include "13_roman_to_integer.h"
#include "14_longest_common_prefix.h"
#include "15_3sum.h"
#include "18_4sum.h"
#include "20_valid_parentheses.h"
#include "21_merge_two_sorted_lists.h"
#include "23_merge_k_sorted_lists.h"
#include "26_remove_duplicates_from_sorted_array.h"
#include "27_remove_element.h"
#include "28_find_the_index_of_the_first_occurrence_in_a_string.h"
#include "33_search_in_rotated_sorted_array.h"
#include "42_trapping_rain_water.h"
#include "45_jump_game_II.h"
#include "49_group_anagrams.h"
#include "55_jump_game.h"
#include "56_merge_intervals.h"
#include "58_length_of_last_word.h"
#include "62_unique_paths.h"
#include "66_plus_one.h"
#include "69_sqrt_x.h"
#include "71_simplify_path.h"
#include "74_search_2D_matrix.h"
#include "80_remove_duplicates_from_sorted_array_II.h"
#include "81_search_in_rotated_sorted_arrayII.h"
#include "88_merge_sorted_array.h"
#include "92_reverse_linked_list_II.h"
#include "101_symmetric_tree.h"
#include "110_balanced_binary_tree.h"
#include "120_triangle.h"
#include "121_best_time_to_buy_and_sell_stock.h"
#include "122_best_time_to_buy_and_sell_stock_II.h"
#include "125_valid_palindrome.h"
#include "134_gas_station.h"
#include "135_candy.h"
#include "136_single_number.h"
#include "141_linked_list_cycle.h"
#include "150_evaluate_reverse_polish_notation.h"
#include "151_reverse_words_in_a_string.h"
#include "153_find_minimum_in_rotated_sorted_array.h"
#include "155_min_stack.h"
#include "167_two_sumII_input_array_is_sorted.h"
#include "169_majority_element.h"
#include "189_rotate_array.h"
#include "200_number_of_islands.h"
#include "205_isomorphic_strings.h"
#include "206_reverse_linked_list.h"
#include "224_basic_calculator.h"
#include "238_product_of_array_except_self.h"
#include "239_sliding_window_maximum.h"
#include "242_valid_anagram.h"
#include "274_h_index.h"
#include "301_remove_invalid_parentheses.h"
#include "309_best_time_to_buy_and_sell_stock_with_cooldown.h"
#include "347_top_k_frequent_elements.h"
#include "349_intersection_of_two_arrays.h"
#include "373_find_k_pairs_with_smallest_sums.h"
#include "374_guess_number_higher_or_lower.h"
#include "380_insert_delete_get_random_O_1.h"
#include "383_ransom_note.h"
#include "392_is_subsequence.h"
#include "412_fizz_buzz.h"
#include "424_longest_repeating_character_replacement.h"
#include "438_find_all_anagrams_in_a_string.h"
#include "480_sliding_window_median.h"
#include "653_two_sum_IV_input_is_a_BST.h"
#include "692_top_k_frequent_words.h"
#include "704_binary_search.h"
#include "763_partition_labels.h"
#include "1114_print_in_order.h"
#include "1115_print_foobar_alternately.h"
#include "1116_print_zero_even_odd.h"
#include "1117_building_H2O.h"
#include "1195_fizz_buzz_multithreaded.h"
#include "1226_the_dining_philosophers.h"
#include "1279_traffic_light_controlled_intersection.h"
#include "3531_count_covered_buildings.h"


int main()
{
    //////////////////////
    /**
     * 1. Two Sum
     */
#if 1
    {
        std::vector<int> nums1{ 2, 7, 11, 15 };
        std::vector<int> nums2{ 3, 2, 4 };
        std::vector<int> nums3{ 3, 3 };

        {
            _1::Solution<ver1> s{};
            auto output1 = s.twoSum(nums1, 9);
            custom_assert("{ 0, 1 }" == vector_to_string(output1));
            auto output2 = s.twoSum(nums2, 6);
            custom_assert("{ 1, 2 }" == vector_to_string(output2));
            auto output3 = s.twoSum(nums3, 6);
            custom_assert("{ 0, 1 }" == vector_to_string(output3));
        }
        {
            _1::Solution<ver2> s{};
            auto output1 = s.twoSum(nums1, 9);
            custom_assert("{ 0, 1 }" == vector_to_string(output1));
            auto output2 = s.twoSum(nums2, 6);
            custom_assert("{ 1, 2 }" == vector_to_string(output2));
            auto output3 = s.twoSum(nums3, 6);
            custom_assert("{ 0, 1 }" == vector_to_string(output3));
        }
    }
#endif
    //////////////////////
    /**
     * 2. Add Two Numbers
     */
#if 1
    {
        _2::Solution s{};

        UniqueListNode l1_1(ListNodeHelper::createList({ 2, 4, 3 }));
        UniqueListNode l1_2(ListNodeHelper::createList({ 5, 6, 4 }));
        UniqueListNode temp1(s.addTwoNumbers(l1_1.get(), l1_2.get()));
        custom_assert("{ 7, 0, 8 }" == ListNodeHelper::convertListNodeToString(temp1.get()));

        UniqueListNode l2_1(ListNodeHelper::createList({ 0 }));
        UniqueListNode l2_2(ListNodeHelper::createList({ 0 }));
        UniqueListNode temp2(s.addTwoNumbers(l2_1.get(), l2_2.get()));
        custom_assert("{ 0 }" == ListNodeHelper::convertListNodeToString(temp2.get()));

        UniqueListNode l3_1(ListNodeHelper::createList({ 9, 9, 9, 9, 9, 9, 9 }));
        UniqueListNode l3_2(ListNodeHelper::createList({ 9, 9, 9, 9 }));
        UniqueListNode temp3(s.addTwoNumbers(l3_1.get(), l3_2.get()));
        custom_assert("{ 8, 9, 9, 9, 0, 0, 0, 1 }" == ListNodeHelper::convertListNodeToString(temp3.get()));
    }
#endif
    //////////////////////
    /**
     * 6. Zigzag Conversion
     */
#if 1
    {
        _6::Solution s{};
        custom_assert("PAHNAPLSIIGYIR" == s.convert("PAYPALISHIRING", 3));
        custom_assert("PINALSIGYAHRPI" == s.convert("PAYPALISHIRING", 4));
        custom_assert("A" == s.convert("A", 1));
    }
#endif
    //////////////////////
    /**
     * 9. Palindrome Number
     */
#if 1
    {
        int x1 = 121;
        int x2 = -121;
        int x3 = 10;

        _9::Solution s{};
        custom_assert(true == s.isPalindrome(x1));
        custom_assert(false == s.isPalindrome(x2));
        custom_assert(false == s.isPalindrome(x3));
    }
#endif
    //////////////////////
    /**
     * 11. Container With Most Water
     */
#if 1
    {
        std::vector<int> height_1{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
        std::vector<int> height_2{ 1, 1 };

        _11::Solution s{};
        custom_assert(49 == s.maxArea(height_1));
        custom_assert(1 == s.maxArea(height_2));
    }
#endif
    //////////////////////
    /**
     * 12. Integer to Roman
     */
#if 1
    {
        int num1 = 3749;
        int num2 = 58;
        int num3 = 1994;

        {
            _12::Solution<ver1> s{};
            custom_assert("MMMDCCXLIX" == s.intToRoman(num1));
            custom_assert("LVIII" == s.intToRoman(num2));
            custom_assert("MCMXCIV" == s.intToRoman(num3));
        }
        {
            _12::Solution<ver2> s{};
            custom_assert("MMMDCCXLIX" == s.intToRoman(num1));
            custom_assert("LVIII" == s.intToRoman(num2));
            custom_assert("MCMXCIV" == s.intToRoman(num3));
        }
    }
#endif
    //////////////////////
    /**
     * 13. Roman to Integer
     */
#if 1
    {
        std::string s1{ "III" };
        std::string s2{ "LVIII" };
        std::string s3{ "MCMXCIV" };

        _13::Solution s{};
        custom_assert(3 == s.romanToInt(s1));
        custom_assert(58 == s.romanToInt(s2));
        custom_assert(1994 == s.romanToInt(s3));
    }
#endif
    //////////////////////
    /**
     * 14. Longest Common Prefix
     */
#if 1
    {
        std::vector<std::string> strs_1{ "flower", "flow", "flight" };
        std::vector<std::string> strs_2{ "dog", "racecar", "car" };
        std::vector<std::string> strs_3{ "a" };

        _14::Solution s{};
        custom_assert("fl" == s.longestCommonPrefix(strs_1));
        custom_assert("" == s.longestCommonPrefix(strs_2));
        custom_assert("a" == s.longestCommonPrefix(strs_3));
    }
#endif
    //////////////////////
    /**
     * 15. 3Sum
     */
#if 1
    {
        std::vector<int> l0{ -1, 0, 1, 2, -1, -4 }; // Output: [[-1,-1,2],[-1,0,1]]
        std::vector<int> l1{ 0, 1 ,1 };             // Output: []
        std::vector<int> l2{ 0, 0, 0 };             // Output: [[0,0,0]]
        std::vector<int> l3{ 0, 0 };                // Output: []

        {
            _15::Solution<ver1> s;
            custom_assert(2 == s.threeSum(l0).size());
            custom_assert(0 == s.threeSum(l1).size());
            custom_assert(1 == s.threeSum(l2).size());
            custom_assert(0 == s.threeSum(l3).size());
        }
        {
            _15::Solution<ver2> s;
            custom_assert(2 == s.threeSum(l0).size());
            custom_assert(0 == s.threeSum(l1).size());
            custom_assert(1 == s.threeSum(l2).size());
            custom_assert(0 == s.threeSum(l3).size());
        }
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
        custom_assert(0 == s.fourSum(l0, 0).size());
        custom_assert(3 == s.fourSum(l1, 0).size());
        custom_assert(1 == s.fourSum(l2, 8).size());
        custom_assert(8 == s.fourSum(l3, 0).size());
        custom_assert(0 == s.fourSum(l4, 0).size());
        custom_assert(2 == s.fourSum(l5, 0).size());
    }
#endif
    //////////////////////
    /**
     * 20. Valid Parentheses
     */
#if 1
    {
        std::string s_1 = "()";
        std::string s_2 = "()[]{}";
        std::string s_3 = "(]";
        std::string s_4 = "([])";
        std::string s_5 = "([)]";

        _20::Solution s{};
        custom_assert(true == s.isValid(s_1));
        custom_assert(true == s.isValid(s_2));
        custom_assert(false == s.isValid(s_3));
        custom_assert(true == s.isValid(s_4));
        custom_assert(false == s.isValid(s_5));
    }
#endif
    //////////////////////
    /**
     * 21. Merge Two Sorted Lists
     */
#if 1
    {
        _21::Solution s{};

        std::vector<int> data0_1{ 1, 2, 4 };
        std::vector<int> data0_2{ 1, 3, 4 };
        UniqueListNode list0_1(ListNodeHelper::createList(data0_1));
        UniqueListNode list0_2(ListNodeHelper::createList(data0_2));
        UniqueListNode result(s.mergeTwoLists(list0_1.release(), list0_2.release()));
        custom_assert("{ 1, 1, 2, 3, 4, 4 }" == ListNodeHelper::convertListNodeToString(result.get()));

        std::vector<int> data1_1{ };
        std::vector<int> data1_2{ };
        UniqueListNode list1_1(ListNodeHelper::createList(data1_1));
        UniqueListNode list1_2(ListNodeHelper::createList(data1_2));
        UniqueListNode result2(s.mergeTwoLists(list1_1.release(), list1_2.release()));
        custom_assert("{ }" == ListNodeHelper::convertListNodeToString(result2.get()));

        std::vector<int> data2_1{ };
        std::vector<int> data2_2{ 0 };
        UniqueListNode list2_1(ListNodeHelper::createList(data2_1));
        UniqueListNode list2_2(ListNodeHelper::createList(data2_2));
        UniqueListNode result3(s.mergeTwoLists(list2_1.release(), list2_2.release()));
    }
#endif
    //////////////////////
    /**
     * 23. Merge k Sorted Lists algorithm
     */
#if 1
    {
        { // recursion ver
            ListNode* l1_1 = new ListNode(1, new ListNode(4, new ListNode(5)));
            ListNode* l1_2 = new ListNode(1, new ListNode(3, new ListNode(4)));
            ListNode* l1_3 = new ListNode(2, new ListNode(6));

            // [[1,4,5],[1,3,4],[2,6]]
            std::vector<ListNode*> lists1 = { l1_1, l1_2, l1_3 };
            // []
            std::vector<ListNode*> lists2;
            // [[]]
            std::vector<ListNode*> lists3 = { nullptr };

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

        { // priority_queue ver
            std::vector<int> data1{ 1, 4, 5 };
            std::vector<int> data2{ 1, 3, 4 };
            std::vector<int> data3 = { 2, 6 };

            ListNode* list1 = ListNodeHelper::createList(data1);
            ListNode* list2 = ListNodeHelper::createList(data2);
            ListNode* list3 = ListNodeHelper::createList(data3);

            // [[1,4,5],[1,3,4],[2,6]]
            std::vector<ListNode*> vecs = { list1, list2, list3 };

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
     * 26. Remove Duplicates from Sorted Array
     */
#if 1
    {
        {
            std::vector<int> nums_1{ 1, 1, 2 };
            std::vector<int> nums_2{ 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };

            _26::Solution<ver1> s{};
            custom_assert(2 == s.removeDuplicates(nums_1)); // Output: 2, nums = [1,2,_]
            custom_assert(5 == s.removeDuplicates(nums_2)); // Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
        }
        {
            std::vector<int> nums_1{ 1, 1, 2 };
            std::vector<int> nums_2{ 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };

            _26::Solution<ver2> s{};
            custom_assert(2 == s.removeDuplicates(nums_1)); // Output: 2, nums = [1,2,_]
            custom_assert(5 == s.removeDuplicates(nums_2)); // Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
        }
    }
#endif
    //////////////////////
    /**
     * 27. Remove Element
     */
#if 1
    {
        std::vector<int> nums_1{ 3, 2, 2, 3 };
        int val_1 = 3;
        std::vector<int> nums_2{ 0, 1, 2, 2, 3, 0, 4, 2 };
        int val_2 = 2;

        {
            _27::Solution<ver1> s{};
            custom_assert(2 == s.removeElement(nums_1, val_1)); // Output: 2, nums = [2,2,_,_]
            custom_assert(5 == s.removeElement(nums_2, val_2)); // Output: 5, nums = [0,1,4,0,3,_,_,_]
        }
        {
            _27::Solution<ver2> s{};
            custom_assert(2 == s.removeElement(nums_1, val_1)); // Output: 2, nums = [2,2,_,_]
            custom_assert(5 == s.removeElement(nums_2, val_2)); // Output: 5, nums = [0,1,4,0,3,_,_,_]
        }
    }
#endif
    //////////////////////
    /**
     * 28. Find the Index of the First Occurrence in a String
     */
#if 1
    {
        std::string haystack_1 = "sadbutsad";
        std::string needle_1 = "sad";
        std::string haystack_2 = "ltcode";
        std::string needle_2 = "lto";
        std::string haystack_3 = "hello";
        std::string needle_3 = "ll";
        std::string haystack_4 = "mississippi";
        std::string needle_4 = "issip";
        std::string haystack_5 = "mississippi";
        std::string needle_5 = "issipi";
        std::string haystack_6 = "mississippi";
        std::string needle_6 = "";

        {
            _28::Solution<ver1> s{};
            custom_assert(0 == s.strStr(haystack_1, needle_1));
            custom_assert(-1 == s.strStr(haystack_2, needle_2));
            custom_assert(2 == s.strStr(haystack_3, needle_3));
            custom_assert(4 == s.strStr(haystack_4, needle_4));
            custom_assert(-1 == s.strStr(haystack_5, needle_5));
            custom_assert(0 == s.strStr(haystack_6, needle_6));
        }
        {
            _28::Solution<ver2> s{};
            custom_assert(0 == s.strStr(haystack_1, needle_1));
            custom_assert(-1 == s.strStr(haystack_2, needle_2));
            custom_assert(2 == s.strStr(haystack_3, needle_3));
            custom_assert(4 == s.strStr(haystack_4, needle_4));
            custom_assert(-1 == s.strStr(haystack_5, needle_5));
            custom_assert(0 == s.strStr(haystack_6, needle_6));
        }
        {
            _28::Solution<ver3> s{};
            custom_assert(0 == s.strStr(haystack_1, needle_1));
            custom_assert(-1 == s.strStr(haystack_2, needle_2));
            custom_assert(2 == s.strStr(haystack_3, needle_3));
            custom_assert(4 == s.strStr(haystack_4, needle_4));
            custom_assert(-1 == s.strStr(haystack_5, needle_5));
            custom_assert(0 == s.strStr(haystack_6, needle_6));
        }
        {
            _28::Solution<ver4> s{};
            custom_assert(0 == s.strStr(haystack_1, needle_1));
            custom_assert(-1 == s.strStr(haystack_2, needle_2));
            custom_assert(2 == s.strStr(haystack_3, needle_3));
            custom_assert(4 == s.strStr(haystack_4, needle_4));
            custom_assert(-1 == s.strStr(haystack_5, needle_5));
            custom_assert(0 == s.strStr(haystack_6, needle_6));
        }
    }
#endif
    //////////////////////
    /**
     * 33. Search in Rotated Sorted Array
     */
#if 1
    {
        std::vector<int> nums_1{ 4, 5, 6, 7, 0, 1, 2 };
        std::vector<int> nums_2{ 4, 5, 6, 7, 0, 1, 2 };
        std::vector<int> nums_3{ 1 };
        std::vector<int> nums_4{ };

        _33::Solution s{};
        custom_assert(4 == s.search(nums_1, 0));
        custom_assert(-1 == s.search(nums_2, 3));
        custom_assert(-1 == s.search(nums_3, 0));
        custom_assert(-1 == s.search(nums_4, 0));
    }
#endif
    //////////////////////
    /**
     * 42. Trapping Rain Water
     */
#if 1
    {
        std::vector<int> height_0 = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
        std::vector<int> height_1 = { 4, 2, 0, 3, 2, 5 };
        std::vector<int> height_2 = { 0 };

        {
            _42::Solution<ver1> s{};
            custom_assert(6 == s.trap(height_0));
            custom_assert(9 == s.trap(height_1));
            custom_assert(0 == s.trap(height_2));
        }
        {
            _42::Solution<ver2> s{};
            custom_assert(6 == s.trap(height_0));
            custom_assert(9 == s.trap(height_1));
            custom_assert(0 == s.trap(height_2));
        }
    }
#endif
    //////////////////////
    /**
     * 45. Jump Game II
     */
#if 1
    {
        std::vector<int> nums_1{ 2, 3, 1, 1, 4 };
        std::vector<int> nums_2{ 2, 3, 0, 1, 4 };
        std::vector<int> nums_3{ 1 };

        {
            _45::Solution<ver1> s{};
            custom_assert(2 == s.jump(nums_1));
            custom_assert(2 == s.jump(nums_2));
            custom_assert(0 == s.jump(nums_3));
        }
        {
            _45::Solution<ver2> s{};
            custom_assert(2 == s.jump(nums_1));
            custom_assert(2 == s.jump(nums_2));
            custom_assert(0 == s.jump(nums_3));
        }
        {
            _45::Solution<ver3> s{};
            custom_assert(2 == s.jump(nums_1));
            custom_assert(2 == s.jump(nums_2));
            custom_assert(0 == s.jump(nums_3));
        }
    }
#endif
    //////////////////////
    /**
     * 49. Group Anagrams
     */
#if 1
    {
        std::vector<std::string> str_1 = { "a" };
        std::vector<std::string> str_2 = { "" };
        std::vector<std::string> str_3 = { "eat", "tea", "tan", "ate", "nat", "bat" };


        _49::Solution s{};

        custom_assert("{ {a} }" == vectors_to_string(s.groupAnagrams(str_1)));
        custom_assert("{ {} }" == vectors_to_string(s.groupAnagrams(str_2)));

        std::vector<std::vector<std::string>> res = s.groupAnagrams(str_3);
        // 1. First, need to sort the words within each nested vector alphabetically.
        for (auto& group : res) {
            std::sort(group.begin(), group.end());
        }
        // 2. Then need to sort the main vector by the number of elements, and if the number is equal, by the alphabet of the first word
        std::sort(res.begin(), res.end(), [](const std::vector<std::string>& a, const std::vector<std::string>& b) {
            if (a.size() != b.size()) {
                return a.size() < b.size();
            }
            return a < b;
            });
        custom_assert("{ {bat}, {nat, tan}, {ate, eat, tea} }" == vectors_to_string(res));

    }
#endif
    //////////////////////
    /**
     * 55. Jump Game
     */
#if 1
    {
        std::vector<int> nums_1{ 2, 3, 1, 1, 4 };
        std::vector<int> nums_2{ 3, 2, 1, 0, 4 };
        std::vector<int> nums_3{ 1 };
        std::vector<int> nums_4{ 1, 2 };

        _55::Solution s{};
        custom_assert(true == s.canJump(nums_1));
        custom_assert(false == s.canJump(nums_2));
        custom_assert(true == s.canJump(nums_3));
        custom_assert(true == s.canJump(nums_4));
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
        custom_assert(3 == case1.size());
        std::vector<std::vector<int>> case2 = s.merge(l1_in); //Output: { {1, 5} }
        custom_assert(1 == case2.size());
        std::vector<std::vector<int>> case3 = s.merge(l2_in); //Output: { {1, 7} }
        custom_assert(1 == case3.size());
    }
#endif
    //////////////////////
    /**
     * 58. Length of Last Word
     */
#if 1
    {
        std::string s_1 = "Hello World";
        std::string s_2 = "   fly me   to   the moon  ";
        std::string s_3 = "luffy is still joyboy";

        _58::Solution s{};
        custom_assert(5 == s.lengthOfLastWord(s_1));
        custom_assert(4 == s.lengthOfLastWord(s_2));
        custom_assert(6 == s.lengthOfLastWord(s_3));
    }
#endif
    //////////////////////
    /**
     * 62. Unique Paths
     */
#if 1
    {
        _62::Solution s{};
        custom_assert(28 == s.uniquePaths(3, 7));
        custom_assert(3 == s.uniquePaths(3, 2));
    }
#endif
    //////////////////////
    /**
     * 66. Plus One
     */
#if 1
    {
        std::vector<int> nums1{ 1, 2, 3 };
        std::vector<int> nums2{ 4, 3, 2, 1 };
        std::vector<int> nums3{ 9 };
        std::vector<int> nums4{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
        std::vector<int> nums5{ 9, 9, 9 };

        {
            _66::Solution<ver1> s{};
            auto output1 = s.plusOne(nums1);
            custom_assert("{ 1, 2, 4 }" == vector_to_string(output1));
            auto output2 = s.plusOne(nums2);
            custom_assert("{ 4, 3, 2, 2 }" == vector_to_string(output2));
            auto output3 = s.plusOne(nums3);
            custom_assert("{ 1, 0 }" == vector_to_string(output3));
            auto output4 = s.plusOne(nums4);
            custom_assert("{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 1 }" == vector_to_string(output4));
            auto output5 = s.plusOne(nums5);
            custom_assert("{ 1, 0, 0, 0 }" == vector_to_string(output5));
        }
        {
            _66::Solution<ver2> s{};
            auto output1 = s.plusOne(nums1);
            custom_assert("{ 1, 2, 4 }" == vector_to_string(output1));
            auto output2 = s.plusOne(nums2);
            custom_assert("{ 4, 3, 2, 2 }" == vector_to_string(output2));
            auto output3 = s.plusOne(nums3);
            custom_assert("{ 1, 0 }" == vector_to_string(output3));
            auto output4 = s.plusOne(nums4);
            custom_assert("{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 1 }" == vector_to_string(output4));
            auto output5 = s.plusOne(nums5);
            custom_assert("{ 1, 0, 0, 0 }" == vector_to_string(output5));
        }
    }
#endif
    //////////////////////
    /**
     * 69. Sqrt(x)
     */
#if 1
    {
        int x1 = 4;
        int x2 = 8;

        _69::Solution s{};
        custom_assert(2 == s.mySqrt(x1));
        custom_assert(2 == s.mySqrt(x2));
    }
#endif
    //////////////////////
    /**
     * 71. Simplify Path
     */
#if 1
    {
        {
            _71::Solution<ver1> s{};
            custom_assert("/home" == s.simplifyPath("/home/"));
            custom_assert("/home/foo" == s.simplifyPath("/home//foo/"));
            custom_assert("/home/user/Pictures" == s.simplifyPath("/home/user/Documents/../Pictures"));
            custom_assert("/" == s.simplifyPath("/../"));
            custom_assert("/.../b/d" == s.simplifyPath("/.../a/../b/c/../d/./"));
        }
        {
            _71::Solution<ver2> s{};
            custom_assert("/home" == s.simplifyPath("/home/"));
            custom_assert("/home/foo" == s.simplifyPath("/home//foo/"));
            custom_assert("/home/user/Pictures" == s.simplifyPath("/home/user/Documents/../Pictures"));
            custom_assert("/" == s.simplifyPath("/../"));
            custom_assert("/.../b/d" == s.simplifyPath("/.../a/../b/c/../d/./"));
        }
    }
#endif
    //////////////////////
    /**
     * 74. Search a 2D Matrix
     */
#if 1
    {
        std::vector<std::vector<int>> matrix0{ {1,3,5,7}, {10,11,16,20}, {23,30,34,60} };
        std::vector<std::vector<int>> matrix1{ {1} };
        std::vector<std::vector<int>> matrix2{ {1, 3} };
        {
            _74::Solution<ver1> s{};
            custom_assert(true == s.searchMatrix(matrix0, 3));
            custom_assert(false == s.searchMatrix(matrix0, 13));
            custom_assert(true == s.searchMatrix(matrix1, 1));
            custom_assert(false == s.searchMatrix(matrix1, 0));
            custom_assert(true == s.searchMatrix(matrix2, 3));
            custom_assert(true == s.searchMatrix(matrix2, 1));
            custom_assert(false == s.searchMatrix(matrix2, 0));
        }
        {
            _74::Solution<ver2> s{};
            custom_assert(true == s.searchMatrix(matrix0, 3));
            custom_assert(false == s.searchMatrix(matrix0, 13));
            custom_assert(true == s.searchMatrix(matrix1, 1));
            custom_assert(false == s.searchMatrix(matrix1, 0));
            custom_assert(true == s.searchMatrix(matrix2, 3));
            custom_assert(true == s.searchMatrix(matrix2, 1));
            custom_assert(false == s.searchMatrix(matrix2, 0));
        }
    }
#endif
    //////////////////////
    /**
     * 80. Remove Duplicates from Sorted Array II
     */
#if 1
    {
        {
            std::vector<int> nums_1{ 1, 1, 1, 2, 2, 3 };
            std::vector<int> nums_2{ 0, 0, 1, 1, 1, 1, 2, 3, 3 };
            _80::Solution<ver1> s{};
            custom_assert(5 == s.removeDuplicates(nums_1)); // Output: 5, nums = [1,1,2,2,3,_]
            custom_assert(7 == s.removeDuplicates(nums_2)); // Output: 7, nums = [0,0,1,1,2,3,3,_,_]
        }
        {
            std::vector<int> nums_1{ 1, 1, 1, 2, 2, 3 };
            std::vector<int> nums_2{ 0, 0, 1, 1, 1, 1, 2, 3, 3 };
            _80::Solution<ver2> s{};
            custom_assert(5 == s.removeDuplicates(nums_1)); // Output: 5, nums = [1,1,2,2,3,_]
            custom_assert(7 == s.removeDuplicates(nums_2)); // Output: 7, nums = [0,0,1,1,2,3,3,_,_]
        }
    }
#endif
    //////////////////////
    /**
     * 81. Search in Rotated Sorted Array II
     */
#if 1
    {
        std::vector<int> nums_1{ 2, 5, 6, 0, 0, 1, 2 };
        std::vector<int> nums_2{ 2, 5, 6, 0, 0, 1, 2 };
        std::vector<int> nums_3{ };

        _81::Solution s{};
        custom_assert(true == s.search(nums_1, 0));
        custom_assert(false == s.search(nums_2, 3));
        custom_assert(false == s.search(nums_3, 0));
    }
#endif
    //////////////////////
    /**
     * 88. Merge Sorted Array
     */
#if 1
    {
        std::vector<int> nums0_1{ 1, 2, 3, 0, 0, 0 };
        std::vector<int> nums0_2{ 2, 5, 6 };
        std::vector<int> nums1_1{ 1 };
        std::vector<int> nums1_2{ };
        std::vector<int> nums2_1{ 0 };
        std::vector<int> nums2_2{ 1 };

        _88::Solution s{};
        s.merge(nums0_1, 3, nums0_2, 3); //Output: [1,2,2,3,5,6]
        custom_assert("{ 1, 2, 2, 3, 5, 6 }" == vector_to_string(nums0_1));
        s.merge(nums1_1, 1, nums1_2, 0); //Output: [1]
        custom_assert("{ 1 }" == vector_to_string(nums1_1));
        s.merge(nums2_1, 0, nums2_2, 1); //Output: [1]
        custom_assert("{ 1 }" == vector_to_string(nums2_1));
    }
#endif
    //////////////////////
    /**
     * 92. Reverse Linked List II
     */
#if 1
    {
        _92::Solution s{};

        UniqueListNode l1(ListNodeHelper::createList({ 1, 2, 3, 4, 5 }));
        UniqueListNode temp(s.reverseBetween(l1.release(), 2, 4));
        custom_assert("{ 1, 4, 3, 2, 5 }" == ListNodeHelper::convertListNodeToString(temp.get()));
    }
#endif
    //////////////////////
    /**
     * 101. Symmetric Tree
     */
#if 1
    {
        //root = [1,2,2,3,4,4,3]
        auto tn1 = std::make_unique<SmartPointer::TreeNode>(
            1,
            std::make_unique<SmartPointer::TreeNode>(
                2,
                std::make_unique<SmartPointer::TreeNode>(3),
                std::make_unique<SmartPointer::TreeNode>(4)),
            std::make_unique<SmartPointer::TreeNode>(
                2,
                std::make_unique<SmartPointer::TreeNode>(4),
                std::make_unique<SmartPointer::TreeNode>(3)));

        // root = [1,2,2,null,3,null,3]
        auto tn2 = std::make_unique<SmartPointer::TreeNode>(
            1,
            std::make_unique<SmartPointer::TreeNode>(
                2,
                nullptr,
                std::make_unique<SmartPointer::TreeNode>(3)),
            std::make_unique<SmartPointer::TreeNode>(
                2,
                nullptr,
                std::make_unique<SmartPointer::TreeNode>(3)));
        // root = [1,2,2,2,null,2]
        auto tn3 = std::make_unique<SmartPointer::TreeNode>(
            1,
            std::make_unique<SmartPointer::TreeNode>(
                2,
                std::make_unique<SmartPointer::TreeNode>(2),
                nullptr),
            std::make_unique<SmartPointer::TreeNode>(
                2,
                std::make_unique<SmartPointer::TreeNode>(2),
                nullptr));

        {
            _101::Solution<ver1> s{};
            custom_assert(true == s.isSymmetric(tn1.get()));
            custom_assert(false == s.isSymmetric(tn2.get()));
            custom_assert(false == s.isSymmetric(tn3.get()));
        }
        {
            _101::Solution<ver2> s{};
            custom_assert(true == s.isSymmetric(tn1.get()));
            custom_assert(false == s.isSymmetric(tn2.get()));
            custom_assert(false == s.isSymmetric(tn3.get()));
        }
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
        custom_assert(true == s.isBalanced(tn1));
        s.destroy(tn1);
        custom_assert(false == s.isBalanced(tn2));
        s.destroy(tn2);
        custom_assert(true == s.isBalanced(tn3));
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
        custom_assert(11 == s.minimumTotal(l0));
        custom_assert(-10 == s.minimumTotal(l1));
        custom_assert(11 == s.minimumTotal(l2));
        custom_assert(-1 == s.minimumTotal(l3));
        custom_assert(0 == s.minimumTotal(l4));
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
        custom_assert(5 == s.maxProfit(prices_1));
        std::vector<int> prices_2{ 7, 6, 4, 3, 1 };
        custom_assert(0 == s.maxProfit(prices_2));
        std::vector<int> prices_3{ 1, 2 };
        custom_assert(1 == s.maxProfit(prices_3));
        std::vector<int> prices_4{ 2, 9, 1, 7, 4 };
        custom_assert(7 == s.maxProfit(prices_4));
        std::vector<int> prices_5{ 2 };
        custom_assert(0 == s.maxProfit(prices_5));
    }
#endif
    //////////////////////
    /**
     * 122. Best Time to Buy and Sell Stock II
     */
#if 1
    {
        std::vector<int> prices_1{ 7, 1, 5, 3, 6, 4 };
        std::vector<int> prices_2{ 1, 2, 3, 4, 5 };
        std::vector<int> prices_3{ 7, 6, 4, 3, 1 };

        _122::Solution s{};
        custom_assert(7 == s.maxProfit(prices_1));
        custom_assert(4 == s.maxProfit(prices_2));
        custom_assert(0 == s.maxProfit(prices_3));
    }
#endif
    //////////////////////
    /**
     * 125. Valid Palindrome
     */
#if 1
    {
        std::string s_1 = "A man, a plan, a canal: Panama";
        std::string s_2 = "race a car";
        std::string s_3 = " ";

        _125::Solution s{};
        custom_assert(true == s.isPalindrome(s_1));
        custom_assert(false == s.isPalindrome(s_2));
        custom_assert(true == s.isPalindrome(s_3));
    }
#endif
    //////////////////////
    /**
     * 134. Gas Station
     */
#if 1
    {
        std::vector<int> gas_0{ 1, 2, 3, 4, 5 };
        std::vector<int> cost_0{ 3, 4, 5, 1, 2 };
        std::vector<int> gas_1{ 2, 3, 4 };
        std::vector<int> cost_1{ 3, 4, 3 };

        {
            _134::Solution<ver1> s{};
            custom_assert(3 == s.canCompleteCircuit(gas_0, cost_0));
            custom_assert(-1 == s.canCompleteCircuit(gas_1, cost_1));
        }
        {
            _134::Solution<ver2> s{};
            custom_assert(3 == s.canCompleteCircuit(gas_0, cost_0));
            custom_assert(-1 == s.canCompleteCircuit(gas_1, cost_1));
        }
    }
#endif
    //////////////////////
    /**
     * 135. Candy
     */
#if 1
    {
        std::vector<int> ratings_0 = { 1, 0, 2 };
        std::vector<int> ratings_1 = { 1, 2, 2 };
        std::vector<int> ratings_2 = { 1, 3, 2, 2, 1 };
        std::vector<int> ratings_3 = { 1, 2, 87, 87, 87, 2, 1 };

        _135::Solution s{};
        custom_assert(5 == s.candy(ratings_0));
        custom_assert(4 == s.candy(ratings_1));
        custom_assert(7 == s.candy(ratings_2));
        custom_assert(13 == s.candy(ratings_3));
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
        custom_assert(1 == s.singleNumber(l1));
        custom_assert(4 == s.singleNumber(l2));
        custom_assert(1 == s.singleNumber(l3));
    }
#endif
    //////////////////////
    /**
     * 141. Linked List Cycle
     */
#if 1
    {
        {
            // [3, 2, 0, -4]
            auto node_4 = new ListNode(-4);
            auto node_0 = new ListNode(0, node_4);
            auto node_2 = new ListNode(2, node_0);
            auto head = new ListNode(3, node_2);
            node_4->next = node_2;

            _141::Solution s{};
            custom_assert(true == s.hasCycle(head));
            ListNodeHelper::freeList(head);
        }
        {
            // [1, 2]
            auto node_2 = new ListNode(2);
            auto head = new ListNode(0, node_2);
            node_2->next = head;

            _141::Solution s{};
            custom_assert(true == s.hasCycle(head));
            ListNodeHelper::freeList(head);
        }
        {
            // [1]
            auto node_1 = new ListNode(1);

            _141::Solution s{};
            custom_assert(false == s.hasCycle(node_1));
            ListNodeHelper::freeList(node_1);
        }
    }
#endif
    //////////////////////
    /**
     * 150. Evaluate Reverse Polish Notation
     */
#if 1
    {
        std::vector<std::string> tokens_1 = { "2", "1", "+", "3", "*" };
        std::vector<std::string> tokens_2 = { "4", "13", "5", "/", "+" };
        std::vector<std::string> tokens_3 = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };

        _150::Solution s{};
        custom_assert(9 == s.evalRPN(tokens_1));
        custom_assert(6 == s.evalRPN(tokens_2));
        custom_assert(22 == s.evalRPN(tokens_3));
    }
#endif
    //////////////////////
    /**
     * 151. Reverse Words in a String
     */
#if 1
    {
        {
            _151::Solution<ver1> s{};
            custom_assert("world hello" == s.reverseWords("  hello world  "));
            custom_assert("blue is sky the" == s.reverseWords("the sky is blue"));
            custom_assert("example good a" == s.reverseWords("a good   example"));
        }
        {
            _151::Solution<ver2> s{};
            custom_assert("world hello" == s.reverseWords("  hello world  "));
            custom_assert("blue is sky the" == s.reverseWords("the sky is blue"));
            custom_assert("example good a" == s.reverseWords("a good   example"));
        }
    }
#endif
    //////////////////////
    /**
     * 153. Find Minimum in Rotated Sorted Array
     */
#if 1
    {
        std::vector<int> nums_1{ 3, 4, 5, 1, 2 };
        std::vector<int> nums_2{ 4, 5, 6, 7, 0, 1, 2 };
        std::vector<int> nums_3{ 11, 13, 15, 17 };

        _153::Solution s{};
        custom_assert(1 == s.findMin(nums_1));
        custom_assert(0 == s.findMin(nums_2));
        custom_assert(11 == s.findMin(nums_3));
    }
#endif
    //////////////////////
    /**
     * 155. Min Stack
     */
#if 1
    {
        {
            _155_O_N::MinStack minStack;
            minStack.push(-2);
            minStack.push(0);
            minStack.push(-3);
            custom_assert(-3 == minStack.getMin());
            minStack.pop();
            custom_assert(0 == minStack.top());
            custom_assert(-2 == minStack.getMin());
        }
        {
            _155_O_1::MinStack minStack;
            minStack.push(-2);
            minStack.push(0);
            minStack.push(-3);
            custom_assert(-3 == minStack.getMin());
            minStack.pop();
            custom_assert(0 == minStack.top());
            custom_assert(-2 == minStack.getMin());
        }
    }
#endif
    //////////////////////
    /**
     * 167. Two Sum II - Input Array Is Sorted
     */
#if 1
    {
        std::vector<int> nums1{ 2, 7, 11, 15 };
        std::vector<int> nums2{ 2, 3, 4 };
        std::vector<int> nums3{ -1, 0 };

        _167::Solution s{};
        auto output1 = s.twoSum(nums1, 9);
        custom_assert("{ 1, 2 }" == vector_to_string(output1));
        auto output2 = s.twoSum(nums2, 6);
        custom_assert("{ 1, 3 }" == vector_to_string(output2));
        auto output3 = s.twoSum(nums3, -1);
        custom_assert("{ 1, 2 }" == vector_to_string(output3));
    }
#endif
    //////////////////////
    /**
     * 169. Majority Element
     */
#if 1
    {
        std::vector<int> nums1{ 3, 2, 3 };
        std::vector<int> nums2{ 2, 2, 1, 1, 1, 2, 2 };
        std::vector<int> nums3{ 3, 3, 4 };

        {
            _169::Solution<ver1> s{};
            custom_assert(3 == s.majorityElement(nums1));
            custom_assert(2 == s.majorityElement(nums2));
            custom_assert(3 == s.majorityElement(nums3));
        }
        {
            _169::Solution<ver2> s{};
            custom_assert(3 == s.majorityElement(nums1));
            custom_assert(2 == s.majorityElement(nums2));
            custom_assert(3 == s.majorityElement(nums3));
        }
    }
#endif
    //////////////////////
    /**
     * 189. Rotate Array
     */
#if 1
    {
        {
            std::vector<int> nums1{ 1, 2, 3, 4, 5, 6, 7 };
            int k1 = 3;
            std::vector<int> nums2{ -1, -100, 3, 99 };
            int k2 = 2;

            _189::Solution<ver1> s{};
            s.rotate(nums1, k1);
            custom_assert("{ 5, 6, 7, 1, 2, 3, 4 }" == vector_to_string(nums1));
            s.rotate(nums2, k2);
            custom_assert("{ 3, 99, -1, -100 }" == vector_to_string(nums2));
        }
        {
            std::vector<int> nums1{ 1, 2, 3, 4, 5, 6, 7 };
            int k1 = 3;
            std::vector<int> nums2{ -1, -100, 3, 99 };
            int k2 = 2;

            _189::Solution<ver2> s{};
            s.rotate(nums1, k1);
            custom_assert("{ 5, 6, 7, 1, 2, 3, 4 }" == vector_to_string(nums1));
            s.rotate(nums2, k2);
            custom_assert("{ 3, 99, -1, -100 }" == vector_to_string(nums2));
        }
        {
            std::vector<int> nums1{ 1, 2, 3, 4, 5, 6, 7 };
            int k1 = 3;
            std::vector<int> nums2{ -1, -100, 3, 99 };
            int k2 = 2;

            _189::Solution<ver3> s{};
            s.rotate(nums1, k1);
            custom_assert("{ 5, 6, 7, 1, 2, 3, 4 }" == vector_to_string(nums1));
            s.rotate(nums2, k2);
            custom_assert("{ 3, 99, -1, -100 }" == vector_to_string(nums2));
        }
        {
            std::vector<int> nums1{ 1, 2, 3, 4, 5, 6, 7 };
            int k1 = 3;
            std::vector<int> nums2{ -1, -100, 3, 99 };
            int k2 = 2;

            _189::Solution<ver4> s{};
            s.rotate(nums1, k1);
            custom_assert("{ 5, 6, 7, 1, 2, 3, 4 }" == vector_to_string(nums1));
            s.rotate(nums2, k2);
            custom_assert("{ 3, 99, -1, -100 }" == vector_to_string(nums2));
        }
        {
            std::vector<int> nums1{ 1, 2, 3, 4, 5, 6, 7 };
            int k1 = 3;
            std::vector<int> nums2{ -1, -100, 3, 99 };
            int k2 = 2;

            _189::Solution<ver5> s{};
            s.rotate(nums1, k1);
            custom_assert("{ 5, 6, 7, 1, 2, 3, 4 }" == vector_to_string(nums1));
            s.rotate(nums2, k2);
            custom_assert("{ 3, 99, -1, -100 }" == vector_to_string(nums2));
        }
    }
#endif
    //////////////////////
    /**
     * 200. Number of Islands
     */
#if 1
    {
        std::vector<std::vector<char>> grid1{ {'1', '1', '1', '1', '0'},
                                              {'1', '1', '0', '1', '0'},
                                              {'1', '1', '0', '0', '0'},
                                              {'0', '0', '0', '0', '0'} };

        std::vector<std::vector<char>> grid2{ {'1', '1', '0', '0', '0'},
                                              {'1', '1', '0', '0', '0'},
                                              {'0', '0', '1', '0', '0'},
                                              {'0', '0', '0', '1', '1'} };

        _200::Solution<ver1> s{};
        custom_assert(1 == s.numIslands(grid1));
        custom_assert(3 == s.numIslands(grid2));
    }
    {
        std::vector<std::vector<char>> grid1{ {'1', '1', '1', '1', '0'},
                                              {'1', '1', '0', '1', '0'},
                                              {'1', '1', '0', '0', '0'},
                                              {'0', '0', '0', '0', '0'} };

        std::vector<std::vector<char>> grid2{ {'1', '1', '0', '0', '0'},
                                              {'1', '1', '0', '0', '0'},
                                              {'0', '0', '1', '0', '0'},
                                              {'0', '0', '0', '1', '1'} };

        _200::Solution<ver2> s{};
        custom_assert(1 == s.numIslands(grid1));
        custom_assert(3 == s.numIslands(grid2));
    }
#endif
    //////////////////////
    /**
     * 205. Isomorphic Strings
     */
#if 1
    {
        {
            _205::Solution<ver1> s{};
            custom_assert(false == s.isIsomorphic("f11", "b23"));
            custom_assert(true == s.isIsomorphic("egg", "add"));
            custom_assert(false == s.isIsomorphic("bbbaaaba", "aaabbbba"));
            custom_assert(false == s.isIsomorphic("abc", "dee"));
            custom_assert(true == s.isIsomorphic("paper", "title"));
        }
        {
            _205::Solution<ver2> s{};
            custom_assert(true == s.isIsomorphic("egg", "add"));
            custom_assert(false == s.isIsomorphic("f11", "b23"));
            custom_assert(false == s.isIsomorphic("bbbaaaba", "aaabbbba"));
            custom_assert(false == s.isIsomorphic("abc", "dee"));
            custom_assert(true == s.isIsomorphic("paper", "title"));
        }
        {
            _205::Solution<ver3> s{};
            custom_assert(true == s.isIsomorphic("egg", "add"));
            custom_assert(false == s.isIsomorphic("abc", "dee"));
            custom_assert(false == s.isIsomorphic("f11", "b23"));
            custom_assert(false == s.isIsomorphic("bbbaaaba", "aaabbbba"));
            custom_assert(true == s.isIsomorphic("paper", "title"));
        }
    }
#endif
    //////////////////////
    /**
     * 206. Reverse Linked List
     */
#if 1
    {
        std::vector<int> data1{ 1, 2, 3, 4, 5 };
        std::vector<int> data2{ 1, 2 };
        std::vector<int> data3{ };

        ListNode* list1 = ListNodeHelper::createList(data1);
        ListNode* list2 = ListNodeHelper::createList(data2);
        ListNode* list3 = ListNodeHelper::createList(data3);

        _206::Solution s{};
        // [1, 2, 3, 4, 5]
        ListNode* result1 = s.reverseList(list1);
        custom_assert("{ 5, 4, 3, 2, 1 }" == ListNodeHelper::convertListNodeToString(result1));
        ListNodeHelper::freeList(result1);

        // [1, 2]
        ListNode* result2 = s.reverseList(list2);
        custom_assert("{ 2, 1 }" == ListNodeHelper::convertListNodeToString(result2));
        ListNodeHelper::freeList(result2);

        // []
        ListNode* result3 = s.reverseList(list3);
        custom_assert("{ }" == ListNodeHelper::convertListNodeToString(result3));
        ListNodeHelper::freeList(result3);
    }
#endif
    //////////////////////
    /**
     * 224. Basic Calculator
     */
#if 1
    {
        {
            _224_basic_calculator::Solution s{}; // does not parse correctly a case: "-2 + 1"
            custom_assert(14 == s.calculate("12 + 2"));
            custom_assert(3 == s.calculate(" 2-1 + 2 "));
            custom_assert(23 == s.calculate("(1+(4+5+2)-3)+(6+8)"));
        }
        {
            _224_unary_minus::Solution s{};
            //custom_assert(-1 == s.calculate("-2 + 1"));
            //custom_assert(14 == s.calculate("12 + 2"));
            //custom_assert(3 == s.calculate(" 2-1 + 2 "));
            custom_assert(23 == s.calculate("(1+(4+5+2)-3)+(6+8)"));
        }
    }
#endif
    //////////////////////
    /**
     * 238. Product of Array Except Self
     */
#if 1
    {
        std::vector<int> nums1{ 1, 2, 3, 4 };
        std::vector<int> nums2{ -1, 1, 0, -3, 3 };
        {
            _238::Solution<ver1> s{};
            custom_assert("{ 24, 12, 8, 6 }" == vector_to_string(s.productExceptSelf(nums1)));
            custom_assert("{ 0, 0, 9, 0, 0 }" == vector_to_string(s.productExceptSelf(nums2)));
        }
        {
            _238::Solution<ver2> s{};
            custom_assert("{ 24, 12, 8, 6 }" == vector_to_string(s.productExceptSelf(nums1)));
            custom_assert("{ 0, 0, 9, 0, 0 }" == vector_to_string(s.productExceptSelf(nums2)));
        }
    }
#endif
    //////////////////////
    /**
     * 239. Sliding Window Maximum
     */
#if 1
    {
        std::vector<int> nums1{ 1, 3, -1, -3, 5, 3, 6, 7 };
        std::vector<int> nums2{ 1 };
        std::vector<int> nums3{ 1, 4, 2, 3 };

        {
            _239::Solution<ver1> s{};
            auto output1 = s.maxSlidingWindow(nums1, 3);
            custom_assert("{ 3, 3, 5, 5, 6, 7 }" == vector_to_string(output1));
            auto output2 = s.maxSlidingWindow(nums2, 1);
            custom_assert("{ 1 }" == vector_to_string(output2));
            auto output3 = s.maxSlidingWindow(nums3, 4);
            custom_assert("{ 4 }" == vector_to_string(output3));
        }
        {
            _239::Solution<ver2> s{};
            auto output1 = s.maxSlidingWindow(nums1, 3);
            custom_assert("{ 3, 3, 5, 5, 6, 7 }" == vector_to_string(output1));
            auto output2 = s.maxSlidingWindow(nums2, 1);
            custom_assert("{ 1 }" == vector_to_string(output2));
            auto output3 = s.maxSlidingWindow(nums3, 4);
            custom_assert("{ 4 }" == vector_to_string(output3));
        }
    }
#endif
    //////////////////////
    /**
     * 242. Valid Anagram
     */
#if 1
    {
        std::string s1_1 = "anagram";
        std::string s1_2 = "nagaram";
        std::string s2_1 = "rat";
        std::string s2_2 = "car";
        {
            _242::Solution<ver1> s{};
            custom_assert(true == s.isAnagram(s1_1, s1_2));
            custom_assert(false == s.isAnagram(s2_1, s2_2));
        }
        {
            _242::Solution<ver2> s{};
            custom_assert(true == s.isAnagram(s1_1, s1_2));
            custom_assert(false == s.isAnagram(s2_1, s2_2));
        }
    }
#endif
    //////////////////////
    /**
     * 274. H-Index
     */
#if 1
    {
        std::vector<int> citations1{ 3, 0, 6, 1, 5 };
        std::vector<int> citations2{ 1, 3, 1 };

        _274::Solution s{};
        custom_assert(3 == s.hIndex(citations1));
        custom_assert(1 == s.hIndex(citations2));
    }
#endif
    //////////////////////
    /**
     * 301. Remove Invalid Parentheses
     */
#if 1
    {
        std::string s_1 = "()())()";
        std::string s_2 = "(a)())()";
        std::string s_3 = ")(";
        std::string s_4 = ")(f";

        {
            _301::Solution<ver1> s{};
            custom_assert(std::vector<std::string>({ "(())()", "()()()" }) == s.removeInvalidParentheses(s_1));
            custom_assert(std::vector<std::string>({ "(a())()", "(a)()()" }) == s.removeInvalidParentheses(s_2));
            custom_assert(std::vector<std::string>({ "" }) == s.removeInvalidParentheses(s_3));
            custom_assert(std::vector<std::string>({ "f" }) == s.removeInvalidParentheses(s_4));
        }
        {
            _301::Solution<ver2> s{};
            custom_assert(std::vector<std::string>({ "(())()", "()()()" }) == s.removeInvalidParentheses(s_1));
            custom_assert(std::vector<std::string>({ "(a())()", "(a)()()" }) == s.removeInvalidParentheses(s_2));
            custom_assert(std::vector<std::string>({ "" }) == s.removeInvalidParentheses(s_3));
            custom_assert(std::vector<std::string>({ "f" }) == s.removeInvalidParentheses(s_4));
        }
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
        custom_assert(3 == s.maxProfit(prices_1));
        custom_assert(0 == s.maxProfit(prices_2));
        custom_assert(19 == s.maxProfit(prices_3));
        custom_assert(6 == s.maxProfit(prices_4));
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
        custom_assert("{ 1, 2 }" == vector_to_string(s.topKFrequent(elements_1, k_1)));
        custom_assert("{ 1 }" == vector_to_string(s.topKFrequent(elements_2, k_2)));
        custom_assert("{ 1, 2 }" == vector_to_string(s.topKFrequent(elements_3, k_3)));
    }
#endif
    //////////////////////
    /**
     * 349. Intersection of Two Arrays
     */
#if 1
    {
        std::vector<int> nums0_1{ 1, 2, 2, 1 };
        std::vector<int> nums0_2{ 2, 2 };
        std::vector<int> nums1_1{ 4, 9, 5 };
        std::vector<int> nums1_2{ 9, 4, 9, 8, 4 };

        _349::Solution s{};
        auto output1 = s.intersection(nums0_1, nums0_2);
        custom_assert("{ 2 }" == vector_to_string(output1));
        auto output2 = s.intersection(nums1_1, nums1_2);
        custom_assert("{ 4, 9 }" == vector_to_string(output2));
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
            _373::Solution<ver1> s{};
            custom_assert("{ {1, 2}, {1, 4}, {1, 6} }" == vectors_to_string(s.kSmallestPairs(l0_0, l0_1, k0)));
            custom_assert("{ {1, 1}, {1, 1} }" == vectors_to_string(s.kSmallestPairs(l1_0, l1_1, k1)));
            custom_assert("{ {1, 1}, {1, 1}, {1, 2}, {1, 2}, {2, 1}, {1, 3}, {1, 3}, {2, 2}, {2, 3} }" == vectors_to_string(s.kSmallestPairs(l2_0, l2_1, k2)));
            custom_assert("{ {1, 3}, {2, 3}, {1, 5} }" == vectors_to_string(s.kSmallestPairs(l3_0, l3_1, k3)));
        }
        {
            _373::Solution<ver2> s{};
            custom_assert("{ {1, 2}, {1, 4}, {1, 6} }" == vectors_to_string(s.kSmallestPairs(l0_0, l0_1, k0)));
            custom_assert("{ {1, 1}, {1, 1} }" == vectors_to_string(s.kSmallestPairs(l1_0, l1_1, k1)));
            custom_assert("{ {1, 1}, {1, 1}, {1, 2}, {1, 2}, {2, 1}, {1, 3}, {1, 3}, {2, 2}, {2, 3} }" == vectors_to_string(s.kSmallestPairs(l2_0, l2_1, k2)));
            custom_assert("{ {1, 3}, {2, 3}, {1, 5} }" == vectors_to_string(s.kSmallestPairs(l3_0, l3_1, k3)));
        }
        {
            _373::Solution<ver3> s{};
            custom_assert("{ {1, 2}, {1, 4}, {1, 6} }" == vectors_to_string(s.kSmallestPairs(l0_0, l0_1, k0)));
            custom_assert("{ {1, 1}, {1, 1} }" == vectors_to_string(s.kSmallestPairs(l1_0, l1_1, k1)));
            custom_assert("{ {1, 1}, {1, 1}, {1, 2}, {1, 2}, {2, 1}, {1, 3}, {1, 3}, {2, 2}, {2, 3} }" == vectors_to_string(s.kSmallestPairs(l2_0, l2_1, k2)));
            custom_assert("{ {1, 3}, {2, 3}, {1, 5} }" == vectors_to_string(s.kSmallestPairs(l3_0, l3_1, k3)));
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
        custom_assert(6 == s.guessNumber(10));
        s.setPick(1);
        custom_assert(1 == s.guessNumber(1));
        s.setPick(1);
        custom_assert(1 == s.guessNumber(1));
    }
#endif
    //////////////////////
    /**
     * 380. Insert Delete GetRandom O(1)
     */
#if 1
    {
        _380::RandomizedSet randomizedSet;
        custom_assert(true == randomizedSet.insert(1));
        custom_assert(false == randomizedSet.remove(2));
        custom_assert(true == randomizedSet.insert(2));
        int val = randomizedSet.getRandom();
        custom_assert(val == 1 || val == 2);
        custom_assert(true == randomizedSet.remove(1));
        custom_assert(false == randomizedSet.insert(2));
        custom_assert(2 == randomizedSet.getRandom());
        custom_assert(true == randomizedSet.remove(2));
        custom_assert(false == randomizedSet.remove(2));
    }
#endif
    //////////////////////
    /**
     * 392. Is Subsequence
     */
#if 1
    {
        std::string s1_1 = "abc";
        std::string t1_2 = "ahbgdc";
        std::string s2_1 = "axc";
        std::string t2_2 = "ahbgdc";
        std::string s3_1 = "acb";
        std::string t3_2 = "ahbgdc";
        std::string s4_1 = "aaaaaa";
        std::string t4_2 = "bbaaaa";
        std::string s5_1 = "ahbgdcc";
        std::string t5_2 = "ahbgdc";

        {
            _392::Solution<ver1> s{};
            custom_assert(true == s.isSubsequence(s1_1, t1_2));
            custom_assert(false == s.isSubsequence(s2_1, t2_2));
            custom_assert(false == s.isSubsequence(s3_1, t3_2));
            custom_assert(false == s.isSubsequence(s4_1, t4_2));
            custom_assert(false == s.isSubsequence(s5_1, t5_2));
        }
        {
            _392::Solution<ver2> s{};
            custom_assert(true == s.isSubsequence(s1_1, t1_2));
            custom_assert(false == s.isSubsequence(s2_1, t2_2));
            custom_assert(false == s.isSubsequence(s3_1, t3_2));
            custom_assert(false == s.isSubsequence(s4_1, t4_2));
            custom_assert(false == s.isSubsequence(s5_1, t5_2));
        }
    }
#endif
    //////////////////////
    /**
     * 383. Ransom Note
     */
#if 1
    {
        {
            _383::Solution <ver1> s{};
            custom_assert(true == s.canConstruct("aa", "aab"));
            custom_assert(true == s.canConstruct("aa", "aba"));
            custom_assert(false == s.canConstruct("a", "b"));
            custom_assert(false == s.canConstruct("aa", "ab"));
        }
        {
            _383::Solution <ver2> s{};
            custom_assert(true == s.canConstruct("aa", "aab"));
            custom_assert(true == s.canConstruct("aa", "aba"));
            custom_assert(false == s.canConstruct("a", "b"));
            custom_assert(false == s.canConstruct("aa", "ab"));
        }
    }
#endif
    //////////////////////
    /**
     * 412. Fizz Buzz
     */
#if 1
    {
        _412::Solution s{};
        custom_assert("{ 1, 2, Fizz }" == vector_to_string(s.fizzBuzz(3)));
        custom_assert("{ 1, 2, Fizz, 4, Buzz }" == vector_to_string(s.fizzBuzz(5)));
        std::string output = "{ 1, 2, Fizz, 4, Buzz, Fizz, 7, 8, Fizz, Buzz, 11, Fizz, 13, 14, FizzBuzz }";
        custom_assert(output == vector_to_string(s.fizzBuzz(15)));
    }
#endif
    //////////////////////
    /**
     * 424. Longest Repeating Character Replacement
     */
#if 1
    {
        std::string s_1 = "ABAB";
        std::string s_2 = "AABABBA";

        {
            _424::Solution<ver1> s{};
            custom_assert(4 == s.characterReplacement(s_1, 2));
            custom_assert(4 == s.characterReplacement(s_2, 1));
        }
        {
            _424::Solution<ver2> s{};
            custom_assert(4 == s.characterReplacement(s_1, 2));
            custom_assert(4 == s.characterReplacement(s_2, 1));
        }
    }
#endif
    //////////////////////
    /**
     * 438. Find All Anagrams in a String
     */
#if 1
    {
        std::string s1_1 = "cbaebabacd";
        std::string s1_2 = "abc";
        std::string s2_1 = "abab";
        std::string s2_2 = "ab";

        _438::Solution s{};
        custom_assert("{ 0, 6 }" == vector_to_string(s.findAnagrams(s1_1, s1_2)));
        custom_assert("{ 0, 1, 2 }" == vector_to_string(s.findAnagrams(s2_1, s2_2)));
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
            _480::Solution<ver1> s{};
            auto start_time = get_current_time();
            custom_assert("{ 1.0, -1.0, -1.0, 3.0, 5.0, 6.0 }" == vector_to_string(s.medianSlidingWindow(nums_1, k_1)));
            custom_assert("{ 2.0, 3.0, 3.0, 3.0, 2.0, 3.0, 2.0 }" == vector_to_string(s.medianSlidingWindow(nums_2, k_2)));
            custom_assert("{ 2147483647.0 }" == vector_to_string(s.medianSlidingWindow(nums_3, k_3)));
            custom_assert("{ 2.5 }" == vector_to_string(s.medianSlidingWindow(nums_4, k_4)));
            custom_assert("{ -2147483648.0, -0.5, -0.5, -2147483648.0, -2147483648.0, -0.5, 2147483647.0, 2147483647.0, 2147483647.0, -0.5, -0.5, -0.5 }" == vector_to_string(s.medianSlidingWindow(nums_5, k_5)));
            custom_assert("{ 8.0, 6.0, 8.0, 8.0, 5.0 }" == vector_to_string(s.medianSlidingWindow(num_6, k_6)));
            auto end_time = get_current_time();
            print_elapsed_time(start_time, end_time, "_480_v1");
        }
        {
            _480::Solution<ver2> s{};
            auto start_time = get_current_time();
            custom_assert("{ 1.0, -1.0, -1.0, 3.0, 5.0, 6.0 }" == vector_to_string(s.medianSlidingWindow(nums_1, k_1)));
            custom_assert("{ 2.0, 3.0, 3.0, 3.0, 2.0, 3.0, 2.0 }" == vector_to_string(s.medianSlidingWindow(nums_2, k_2)));
            custom_assert("{ 2147483647.0 }" == vector_to_string(s.medianSlidingWindow(nums_3, k_3)));
            custom_assert("{ 2.5 }" == vector_to_string(s.medianSlidingWindow(nums_4, k_4)));
            custom_assert("{ -2147483648.0, -0.5, -0.5, -2147483648.0, -2147483648.0, -0.5, 2147483647.0, 2147483647.0, 2147483647.0, -0.5, -0.5, -0.5 }" == vector_to_string(s.medianSlidingWindow(nums_5, k_5)));
            custom_assert("{ 8.0, 6.0, 8.0, 8.0, 5.0 }" == vector_to_string(s.medianSlidingWindow(num_6, k_6)));
            auto end_time = get_current_time();
            print_elapsed_time(start_time, end_time, "_480_v2");
        }
        {
            _480::Solution<ver3> s{};
            auto start_time = get_current_time();
            custom_assert("{ 1.0, -1.0, -1.0, 3.0, 5.0, 6.0 }" == vector_to_string(s.medianSlidingWindow(nums_1, k_1)));
            custom_assert("{ 2.0, 3.0, 3.0, 3.0, 2.0, 3.0, 2.0 }" == vector_to_string(s.medianSlidingWindow(nums_2, k_2)));
            custom_assert("{ 2147483647.0 }" == vector_to_string(s.medianSlidingWindow(nums_3, k_3)));
            custom_assert("{ 2.5 }" == vector_to_string(s.medianSlidingWindow(nums_4, k_4)));
            custom_assert("{ -2147483648.0, -0.5, -0.5, -2147483648.0, -2147483648.0, -0.5, 2147483647.0, 2147483647.0, 2147483647.0, -0.5, -0.5, -0.5 }" == vector_to_string(s.medianSlidingWindow(nums_5, k_5)));
            custom_assert("{ 8.0, 6.0, 8.0, 8.0, 5.0 }" == vector_to_string(s.medianSlidingWindow(num_6, k_6)));
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
            _653_two_ptr::Solution s{};
            custom_assert(true == s.findTarget(tn1.get(), 9));
            custom_assert(true == s.findTarget(tn1.get(), 11));
            custom_assert(false == s.findTarget(tn1.get(), 28));
            custom_assert(true == s.findTarget(tn2.get(), 3));
        }
        {
            _653::Solution<_653_BFS_ver> s{};
            custom_assert(false == s.findTarget(tn1.get(), 28));
            custom_assert(true == s.findTarget(tn1.get(), 9));
            custom_assert(true == s.findTarget(tn1.get(), 11));
            custom_assert(true == s.findTarget(tn2.get(), 3));
        }
        {
            _653::Solution<_653_memory_optimal_ver> s{};
            custom_assert(false == s.findTarget(tn1.get(), 28));
            custom_assert(true == s.findTarget(tn1.get(), 9));
            custom_assert(true == s.findTarget(tn1.get(), 11));
            custom_assert(true == s.findTarget(tn2.get(), 3));
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
        custom_assert("{ i, love }" == vector_to_string(s.topKFrequent(words_1, k_1)));
        custom_assert("{ the, is, sunny, day }" == vector_to_string(s.topKFrequent(words_2, k_2)));
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
            custom_assert(4 == s.search(nums1, 9));
            custom_assert(5 == s.search({ -1,0,3,5,9,12 }, 12));
            custom_assert(2 == s.search({ 2, 5, 7, 9 }, 7));
            custom_assert(-1 == s.search(nums1, 2));
            custom_assert(0 == s.search(nums2, 5));
            custom_assert(0 == s.search({ 5 }, 5));
            custom_assert(-1 == s.search(nums3, 5));
            custom_assert(-1 == s.search({}, 5));
            auto end_time = get_current_time();
            print_elapsed_time(start_time, end_time, "_704_recursion_ver");
        }
        {
            auto start_time = get_current_time();
            _704_STL::Solution s{};
            custom_assert(4 == s.search(nums1, 9));
            custom_assert(5 == s.search({ -1,0,3,5,9,12 }, 12));
            custom_assert(2 == s.search({ 2, 5, 7, 9 }, 7));
            custom_assert(-1 == s.search(nums1, 2));
            custom_assert(0 == s.search(nums2, 5));
            custom_assert(0 == s.search({ 5 }, 5));
            custom_assert(-1 == s.search(nums3, 5));
            custom_assert(-1 == s.search({}, 5));
            auto end_time = get_current_time();
            print_elapsed_time(start_time, end_time, "_704_STL_ver");
        }
        {
            auto start_time = get_current_time();
            _704_binary_search::Solution s{};
            custom_assert(4 == s.search(nums1, 9));
            custom_assert(5 == s.search({ -1,0,3,5,9,12 }, 12));
            custom_assert(2 == s.search({ 2, 5, 7, 9 }, 7));
            custom_assert(-1 == s.search(nums1, 2));
            custom_assert(0 == s.search(nums2, 5));
            custom_assert(0 == s.search({ 5 }, 5));
            custom_assert(-1 == s.search(nums3, 5));
            custom_assert(-1 == s.search({}, 5));
            auto end_time = get_current_time();
            print_elapsed_time(start_time, end_time, "_704_binary_search_ver");
        }
        {
            auto start_time = get_current_time();
            _704_linear_search::Solution s{};
            custom_assert(4 == s.search(nums1, 9));
            custom_assert(5 == s.search({ -1,0,3,5,9,12 }, 12));
            custom_assert(2 == s.search({ 2, 5, 7, 9 }, 7));
            custom_assert(-1 == s.search(nums1, 2));
            custom_assert(0 == s.search(nums2, 5));
            custom_assert(0 == s.search({ 5 }, 5));
            custom_assert(-1 == s.search(nums3, 5));
            custom_assert(-1 == s.search({}, 5));
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
        custom_assert(3 == (s.partitionLabels(s_1)).size());
        custom_assert(1 == (s.partitionLabels(s_2)).size());
        custom_assert(1 == (s.partitionLabels(s_3)).size());
        custom_assert(8 == (s.partitionLabels(s_4)).size());
        custom_assert(1 == (s.partitionLabels(s_5)).size());
        custom_assert(2 == (s.partitionLabels(s_6)).size());
    }
#endif
    //////////////////////
    /**
     * 1114. Print in Order
     */
#if 1
    {
        _1114_cv::Foo foo;

        auto printFirst = []() { std::cout << "first"; };
        auto printSecond = []() { std::cout << "second"; };
        auto printThird = []() { std::cout << "third"; };

        std::thread t1([&foo, &printFirst]() { foo.first(printFirst); });
        std::thread t3([&foo, &printThird]() { foo.third(printThird); });
        std::thread t2([&foo, &printSecond]() { foo.second(printSecond); });

        t1.join();
        t2.join();
        t3.join();

        custom_assert("firstsecondthird" == foo.getOutput());
    }
    {
        _1114_atomic::Foo foo;

        auto printFirst = []() { std::cout << "first"; };
        auto printSecond = []() { std::cout << "second"; };
        auto printThird = []() { std::cout << "third"; };

        std::thread t1([&foo, &printFirst]() { foo.first(printFirst); });
        std::thread t2([&foo, &printSecond]() { foo.second(printSecond); });
        std::thread t3([&foo, &printThird]() { foo.third(printThird); });

        t1.join();
        t2.join();
        t3.join();

        custom_assert("firstsecondthird" == foo.getOutput());
    }
#endif
    //////////////////////
    /**
     * 1115. Print FooBar Alternately
     */
#if 1
    {
        _1115::FooBar foobar(1);

        std::cout << std::endl;

        std::function<void()> printFoo = []() { std::cout << "foo"; };
        std::function<void()> printBar = []() { std::cout << "bar"; };

        std::thread t1([&]() { foobar.foo(printFoo); });
        std::thread t2([&]() { foobar.bar(printBar); });

        t1.join();
        t2.join();

        custom_assert("foobar" == foobar.getOutput());
    }
    {
        _1115::FooBar foobar(2);

        std::cout << std::endl;

        auto printFoo = []() { std::cout << "foo"; };
        auto printBar = []() { std::cout << "bar"; };

        std::thread t1([&]() { foobar.foo(printFoo); });
        std::thread t2([&]() { foobar.bar(printBar); });

        t1.join();
        t2.join();

        custom_assert("foobarfoobar" == foobar.getOutput());
    }
#endif
    //////////////////////
    /**
     * 1116. Print Zero Even Odd
     */
#if 1
    {
        _1116::ZeroEvenOdd zeroEvenOdd(2);

        std::cout << std::endl;

        std::function<void(int)> printNumber = [](int x) { std::cout << x; };

        std::thread a([&]() { zeroEvenOdd.zero(printNumber); });
        std::thread b([&]() { zeroEvenOdd.even(printNumber); });
        std::thread c([&]() { zeroEvenOdd.odd(printNumber); });

        a.join();
        b.join();
        c.join();

        custom_assert("0102" == zeroEvenOdd.getOutput());
    }
    {
        _1116::ZeroEvenOdd zeroEvenOdd(5);

        std::cout << std::endl;

        std::function<void(int)> printNumber = [](int x) { std::cout << x; };

        std::thread a([&]() { zeroEvenOdd.zero(printNumber); });
        std::thread b([&]() { zeroEvenOdd.even(printNumber); });
        std::thread c([&]() { zeroEvenOdd.odd(printNumber); });

        a.join();
        b.join();
        c.join();

        custom_assert("0102030405" == zeroEvenOdd.getOutput());
    }
#endif
    //////////////////////
    /**
     * 1117. Building H2O
     */
#if 1
    {
        _1117::H2O h2o;

        std::cout << std::endl;

        auto printHydrogen = []() { std::cout << "H"; };
        auto printOxygen = []() { std::cout << "O"; };

        std::thread hydrogen1([&h2o, &printHydrogen]() { h2o.hydrogen(printHydrogen); });
        std::thread hydrogen2([&h2o, &printHydrogen]() { h2o.hydrogen(printHydrogen); });
        std::thread oxygen([&h2o, &printOxygen]() { h2o.oxygen(printOxygen); });

        hydrogen1.join();
        hydrogen2.join();
        oxygen.join();

        custom_assert("HHO" == h2o.getOutput());
    }
    {
        _1117::H2O h2o;

        std::cout << std::endl;

        auto printHydrogen = []() { std::cout << "H"; };
        auto printOxygen = []() { std::cout << "O"; };

        std::thread h1([&]() { h2o.hydrogen(printHydrogen); });
        std::thread h2([&]() { h2o.hydrogen(printHydrogen); });
        std::thread h3([&]() { h2o.hydrogen(printHydrogen); });
        std::thread h4([&]() { h2o.hydrogen(printHydrogen); });
        std::thread o1([&]() { h2o.oxygen(printOxygen); });
        std::thread o2([&]() { h2o.oxygen(printOxygen); });

        h1.join(); h2.join(); h3.join(); h4.join();
        o1.join(); o2.join();

        std::string out = h2o.getOutput();
        custom_assert(6 == out.size());

        auto isValidH2O = [](const std::string& s) {
            for (int i = 0; i < s.size(); i += 3) {
                std::string molecule = s.substr(i, 3);
                int h = std::count(molecule.begin(), molecule.end(), 'H');
                int o = std::count(molecule.begin(), molecule.end(), 'O');

                if (h != 2 || o != 1)
                    return false;
            }
            return true;
            };

        custom_assert(isValidH2O(out));
    }
    {
        _1117::H2O h2o;

        std::cout << std::endl;

        auto printHydrogen = []() { std::cout << "H"; };
        auto printOxygen = []() { std::cout << "O"; };

        std::vector<std::thread> threads;

        std::string water = "OOHHHHHHO"; //Input
        for (char c : water) {
            if (c == 'H')
                threads.emplace_back([&]() { h2o.hydrogen(printHydrogen); });
            else
                threads.emplace_back([&]() { h2o.oxygen(printOxygen); });
        }

        for (auto& t : threads) t.join();

        std::string out = h2o.getOutput();
        custom_assert(out.size() == water.size());

        auto isValidH2O = [](const std::string& s) {
            for (int i = 0; i < s.size(); i += 3) {
                std::string molecule = s.substr(i, 3);
                int h = std::count(molecule.begin(), molecule.end(), 'H');
                int o = std::count(molecule.begin(), molecule.end(), 'O');
                if (h != 2 || o != 1) return false;
            }
            return true;
            };

        custom_assert(isValidH2O(out));
    }
#endif
    //////////////////////
    /**
     * 1195. Fizz Buzz Multithreaded
     */
#if 1
    {
        _1195::FizzBuzz fizzbuzz(15);

        std::cout << std::endl;

        auto printFizz = []() { std::cout << "fizz"; };
        auto printBuzz = []() { std::cout << "buzz"; };
        auto printFizzBuzz = []() { std::cout << "fizzbuzz"; };
        std::function<void(int)> printNumber = [](int x) { std::cout << x; };

        std::thread a([&]() { fizzbuzz.fizz(printFizz); });
        std::thread b([&]() { fizzbuzz.buzz(printBuzz); });
        std::thread c([&]() { fizzbuzz.fizzbuzz(printFizzBuzz); });
        std::thread d([&]() { fizzbuzz.number(printNumber); });

        a.join();
        b.join();
        c.join();
        d.join();

        custom_assert("12fizz4buzzfizz78fizzbuzz11fizz1314fizzbuzz" == fizzbuzz.getOutput());
    }
    {
        _1195::FizzBuzz fizzbuzz(5);

        std::cout << std::endl;

        auto printFizz = []() { std::cout << "fizz"; };
        auto printBuzz = []() { std::cout << "buzz"; };
        auto printFizzBuzz = []() { std::cout << "fizzbuzz"; };
        std::function<void(int)> printNumber = [](int x) { std::cout << x; };

        std::thread a([&]() { fizzbuzz.fizz(printFizz); });
        std::thread b([&]() { fizzbuzz.buzz(printBuzz); });
        std::thread c([&]() { fizzbuzz.fizzbuzz(printFizzBuzz); });
        std::thread d([&]() { fizzbuzz.number(printNumber); });

        a.join();
        b.join();
        c.join();
        d.join();

        custom_assert("12fizz4buzz" == fizzbuzz.getOutput());
    }
#endif
    //////////////////////
    /**
     * 1226. The Dining Philosophers
     */
#if 1
    {
        std::cout << std::endl;

        _1226::DiningPhilosophers diningPhilosophers;
        std::ostringstream output;
        std::vector<Action> log_verify;
        std::mutex log_mtx;
        std::mutex out_mtx;
        bool first = true;

        auto record = [&](int idPhilosopher, int fork, int operation) {
            std::lock_guard<std::mutex> lock(log_mtx);
            log_verify.push_back({ idPhilosopher, fork, operation });
            };

        auto log = [&](int idPhilosopher, int fork, int operation, const std::string& msg) {
            std::lock_guard<std::mutex> lock(out_mtx);
            if (!first)
                output << ", ";
            output << "[" << idPhilosopher << "," << fork << "," << operation << "]";
            first = false;
            std::cout << msg << "\n";

            record(idPhilosopher, fork, operation);
            };

        output << '[';

        std::vector<std::thread> threads;

        for (int i = 0; i < 5; ++i) {
            threads.emplace_back([&, i]() {
                diningPhilosophers.wantsToEat(i,
                    [&, i]() { log(i, 2, 1, std::to_string(i) + " philosopher pick right fork"); }, // pick right
                    [&, i]() { log(i, 1, 1, std::to_string(i) + " philosopher pick left fork"); },  // pick left
                    [&, i]() { log(i, 0, 3, std::to_string(i) + " philosopher eat"); },             // eat
                    [&, i]() { log(i, 1, 2, std::to_string(i) + " philosopher put left fork"); },   // put left
                    [&, i]() { log(i, 2, 2, std::to_string(i) + " philosopher put right fork"); }   // put right 
                    );
                std::cout << std::endl;
                }
            );
        }

        for (auto& t : threads) {
            t.join();
        }

        output << ']';
        std::cout << output.str() << std::endl;

        verify_logic(log_verify);
    }
#endif
    //////////////////////
    /**
     * 1279. Traffic Light Controlled Intersection
     */
#if 1
    {
        enum class Road : char { A = 'A', B = 'B' };
        auto roadName = [](int road) { return (road == 1) ? static_cast<char>(Road::A) : static_cast<char>(Road::B); };

        {
            std::cout << std::endl;

            _1279::TrafficLight trafficLight;
            std::vector<std::thread> threads;
            std::vector<std::pair<int, char>> cars = { {1, 1}, {3, 1}, {5, 1}, {2, 2}, {4, 2} };
            std::array<int, 5> directions = { 2, 1, 2, 4, 3 };
            std::array<int, 5> arrivalTimes = { 10, 20, 30, 40, 50 };

            for (int i = 0; i < 5; ++i) {
                int car = cars[i].first;
                int road = cars[i].second;
                int direction = directions[i];
                int arrival = arrivalTimes[i];

                threads.emplace_back([=, &trafficLight]() {
                    std::this_thread::sleep_for(std::chrono::milliseconds(arrival));

                    auto crossCar = [=]() { std::cout << "Car " << car << " Has Passed Road " << roadName(road) << " In Direction " << direction << std::endl; };
                    auto turnGreen = [=]() { std::cout << "Traffic Light On Road " << roadName(road) << " Is Green" << std::endl; };

                    trafficLight.carArrived(car, road, direction, turnGreen, crossCar);
                    }
                );
            }

            for (auto& t : threads)
                t.join();
        }
        {
            std::cout << std::endl;

            _1279::TrafficLight trafficLight;
            std::vector<std::thread> threads;
            std::vector<std::pair<int, char>> cars = { {1, 1}, {2, 2}, {3, 1}, {4, 2}, {5, 1} };
            int directions[] = { 2, 4, 3, 3, 1 };
            int arrivalTimes[] = { 10, 20, 30, 40, 40 };

            for (int i = 0; i < cars.size(); ++i) {
                int car = cars[i].first;
                int road = cars[i].second;
                int direction = directions[i];
                int arrival = arrivalTimes[i];

                threads.emplace_back([=, &trafficLight]() {
                    std::this_thread::sleep_for(std::chrono::milliseconds(arrival));

                    auto crossCar = [=]() { std::cout << "Car " << car << " Has Passed Road " << roadName(road) << " In Direction " << direction << std::endl; };
                    auto turnGreen = [=]() { std::cout << "Traffic Light On Road " << roadName(road) << " Is Green" << std::endl; };

                    trafficLight.carArrived(car, road, direction, turnGreen, crossCar);
                    }
                );
            }

            for (auto& t : threads)
                t.join();
        }
    }
#endif
    //////////////////////
    /**
     * 3531. Count Covered Buildings
     */
#if 1
    {
        {
            _3531::Solution<ver1> s{};
            custom_assert(1 == s.countCoveredBuildings(3, { {1, 2}, {2, 2}, {3, 2}, {2, 1}, {2, 3} }));
            custom_assert(0 == s.countCoveredBuildings(3, { {1, 1}, {1, 2}, {2, 1}, {2, 2} }));
            custom_assert(1 == s.countCoveredBuildings(5, { {1, 3}, {3, 2}, {3, 3}, {3, 5}, {5, 3} }));
        }
        {
            _3531::Solution<ver2> s{};
            custom_assert(1 == s.countCoveredBuildings(3, { {1, 2}, {2, 2}, {3, 2}, {2, 1}, {2, 3} }));
            custom_assert(0 == s.countCoveredBuildings(3, { {1, 1}, {1, 2}, {2, 1}, {2, 2} }));
            custom_assert(1 == s.countCoveredBuildings(5, { {1, 3}, {3, 2}, {3, 3}, {3, 5}, {5, 3} }));
        }
    }
#endif

    return 0;
}