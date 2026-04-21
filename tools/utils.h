#pragma once

#include <chrono>
#include <iomanip> // for std::setprecision
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <type_traits>

#define custom_assert(expr) \
    do { \
        if (!(expr)) { \
            std::cerr << "Assertion failed: " << #expr << ", file " << __FILE__ << ", line " << __LINE__ << std::endl; \
			/* it is possible to throw an exception instead of abort */ \
            throw std::runtime_error("Assertion failed"); \
        } \
    } while (0) \


auto get_current_time() {
    return std::chrono::high_resolution_clock::now();
}

void print_elapsed_time(const auto start_time, const auto end_time, const std::string& mesg) {
#if PRINT_ENABLED
    std::cout << mesg << "=" << (end_time - start_time).count() << " sec." << std::endl;
#endif // 0
}


/**
 * Vector of vectors to string.
 * 
 * For example output: "{ {1, 2}, {1, 4}, {1, 6} }"
 */
template <typename T>
std::string vectors_to_string(std::vector<std::vector<T>> vecs) {
    std::ostringstream ss;
    ss << "{ ";

    for (int i = 0; i < vecs.size(); ++i) {
        ss << "{";
        for (int j = 0; j < vecs[i].size(); ++j) {
            ss << vecs[i][j];
            if (j < vecs[i].size() - 1) {
                ss << ", ";
            }
        }
        ss << "}";

        if (i < vecs.size() - 1) {
            ss << ", ";
        }
    }

    ss << " }";

    return ss.str();
}

/**
 * Vector of T to string.
 * 
 * For example output: "{ 1, 2, 4 }" or "{ 8.0, 6.0, 8.0, 8.0, 5.0 }"
 */
template <typename T>
std::string vector_to_string(const std::vector<T>& vec) {
    std::ostringstream ss;
    ss << "{ ";

    for (int i = 0; i < vec.size(); ++i) {
        if constexpr (std::is_arithmetic_v<T>) {  // (c++11) if constexpr (std::is_arithmetic<T>::value) {
            ss << std::fixed << std::setprecision(1) << vec[i];
        }
        else if constexpr (std::is_convertible_v<T, std::string>) {
            ss << static_cast<std::string>(vec[i]);
        }
        else {
            ss << "[unsupported type]";
        }

        if (i < vec.size() - 1) {
            ss << ", ";
        }
    }

    ss << " }";

    return ss.str();
}

//////////////////////
struct Action {
    int idPhil;
    int fork;
    int operation;
};

void verify_logic(const std::vector<Action>& actions) {
    // 1. Check the total number of actions (5 actions * 5 philosophers)
    if (actions.size() != 25) {
        throw std::runtime_error("Missing actions!");
    }

    for (int p = 0; p < 5; ++p) {
        std::vector<Action> p_actions;
        // Select only the actions of a specific philosopher
        for (auto& a : actions) {
            if (a.idPhil == p) {
                p_actions.push_back(a);
            }
        }

        // 2. Check the order eating for each philosopher
        // Expect: [1,1], [2,1], [0,3], [1,2], [2,2] (or 2,1 then 1,1)
        bool has_eat = (p_actions[2].operation == 3);
        if (!has_eat) {
            throw std::runtime_error("Philosopher didn't eat in order!");
        }
    }
}
//////////////////////