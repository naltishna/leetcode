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

std::string vector_to_string(std::vector<std::vector<int>> vecs) {
	std::stringstream ss;
	ss << "{";
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
	ss << "}";

	return ss.str();
}