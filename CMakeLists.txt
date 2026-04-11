# CMakeList.txt : CMake project for leetcode, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("leetcode")

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/test_data
        ${PROJECT_SOURCE_DIR}/tools)

# Add source to this project's executable.
add_executable (leetcode 
"main.cpp"
"src/list_node_helpers.cpp"
"src/1_two_sum.cpp"
"src/2_add_two_numbers.cpp"
"src/9_palindrome_number.cpp"
"src/11_container_with_most_water.cpp"
"src/12_integer_to_roman.cpp"
"src/13_roman_to_integer.cpp"
"src/14_longest_common_prefix.cpp"
"src/15_3sum.cpp"
"src/18_4sum.cpp"
"src/20_valid_parentheses.cpp"
"src/23_merge_k_sorted_lists.cpp"
"src/26_remove_duplicates_from_sorted_array.cpp"
"src/27_remove_element.cpp"
"src/28_find_the_index_of_the_first_occurrence_in_a_string.cpp"
"src/33_search_in_rotated_sorted_array.cpp"
"src/45_jump_game_II.cpp"
"src/49_group_anagrams.cpp"
"src/55_jump_game.cpp"
"src/56_merge_intervals.cpp"
"src/58_length_of_last_word.cpp"
"src/66_plus_one.cpp"
"src/69_sqrt_x.cpp"
"src/74_search_2D_matrix.cpp"
"src/80_remove_duplicates_from_sorted_array_II.cpp"
"src/81_search_in_rotated_sorted_arrayII.cpp"
"src/88_merge_sorted_array.cpp"
"src/101_symmetric_tree.cpp"
"src/110_balanced_binary_tree.cpp"
"src/120_triangle.cpp"
"src/121_best_time_to_buy_and_sell_stock.cpp"
"src/122_best_time_to_buy_and_sell_stock_II.cpp"
"src/125_valid_palindrome.cpp"
"src/136_single_number.cpp"
"src/153_find_minimum_in_rotated_sorted_array.cpp"
"src/167_two_sumII_input_array_is_sorted.cpp"
"src/169_majority_element.cpp"
"src/189_rotate_array.cpp"
"src/200_number_of_islands.cpp"
"src/205_isomorphic_strings.cpp"
"src/206_reverse_linked_list.cpp"
"src/239_sliding_window_maximum.cpp"
"src/242_valid_anagram.cpp"
"src/301_remove_invalid_parentheses.cpp"
"src/309_best_time_to_buy_and_sell_stock_with_cooldown.cpp"
"src/347_top_k_frequent_elements.cpp"
"src/373_find_k_pairs_with_smallest_sums.cpp"
"src/374_guess_number_higher_or_lower.cpp"
"src/380_insert_delete_get_random_O_1.cpp"
"src/383_ransom_note.cpp"
"src/392_is_subsequence.cpp"
"src/424_longest_repeating_character_replacement.cpp"
"src/438_find_all_anagrams_in_a_string.cpp"
"src/480_sliding_window_median.cpp"
"src/653_two_sum_IV_input_is_a_BST.cpp"
"src/692_top_k_frequent_words.cpp"
"src/704_binary_search.cpp"
"src/763_partition_labels.cpp"
"src/1114_print_in_order.cpp"
"src/1115_print_foobar_alternately.cpp"
"src/1116_print_zero_even_odd.cpp"
"src/1117_building_H2O.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET leetcode PROPERTY CXX_STANDARD 20)
endif()

option(USE_O_N_136 "Set ON to enable O(N) version in 136_single_number task or OFF to O(NLogN)" ON)
if (USE_O_N_136)
  target_compile_definitions(${PROJECT_NAME} PRIVATE O_N_136)
endif()

option(PRINT_ENABLED "Enable printing" OFF)
add_compile_definitions(PRINT_ENABLED=${PRINT_ENABLED})