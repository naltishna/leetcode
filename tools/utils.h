#pragma once

#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cassert>

#define my_assert(expr) \
    do { \
        if (!(expr)) { \
            std::cerr << "Assertion failed: " << #expr << ", file " << __FILE__ << ", line " << __LINE__ << std::endl; \
			/* it is possible to throw an exception instead of abort */ \
            throw std::runtime_error("Assertion failed"); \
        } \
    } while (0) \
//#define my_assert assert

auto get_current_time() {
    return std::chrono::high_resolution_clock::now();
}

void print_elapsed_time(const auto start_time, const auto end_time, const std::string& mesg) {
    std::cout << mesg << "=" << (end_time - start_time).count() << " sec." << std::endl;
}