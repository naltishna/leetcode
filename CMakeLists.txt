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
"src/2_add_two_numbers.cpp"
"src/11_container_with_most_water.cpp"
"src/18_4sum.cpp" 
"src/23_merge_k_sorted_lists.cpp" 
"src/56_merge_intervals.cpp"
"src/110_balanced_binary_tree.cpp"
"src/120_triangle.cpp"
"src/121_best_time_to_buy_and_sell_stock.cpp"
"src/136_single_number.cpp"
"src/373_find_k_pairs_with_smallest_sums.cpp"
"src/374_guess_number_higher_or_lower.cpp"
"src/480_sliding_window_median.cpp"
"src/692_top_k_frequent_words.cpp"
"src/704_binary_search.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET leetcode PROPERTY CXX_STANDARD 20)
endif()

option(USE_O_N_136 "Set ON to enable O(N) version in 136_single_number task or OFF to O(NLogN)" ON)
if (USE_O_N_136)
  target_compile_definitions(${PROJECT_NAME} PRIVATE O_N_136)
endif()
