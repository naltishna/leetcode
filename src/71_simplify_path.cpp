#include "71_simplify_path.h"
#include "class_version.h"

#include <vector>
#include <sstream>

namespace _71 {

    /*
     * Time complexity:
     * O(N)
     *
     * Space complexity:
     * O(N)
     */
    template<>
    std::string Solution<v1>::simplifyPath(std::string path) {
        std::vector<std::string> stack;
        int n = path.size();
        size_t i = 0;

        while (i < n) {
            while (i < n && path[i] == '/') {
                i++;
            }

            if (i >= n) {
                break;
            }

            size_t start = i;
            while (i < n && path[i] != '/') {
                i++;
            }

            std::string part = path.substr(start, i - start);
            if (part == ".") {
                continue;
            }
            else if (part == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            }
            else {
                stack.push_back(part);
            }
        }

        std::string result = "/";

        for (size_t j = 0; j < stack.size(); j++) {
            result += stack[j];
            if (j < stack.size() - 1) {
                result += "/";
            }
        }

        return result;
    }

    /*
     * Tokenize the input by '/' and process tokens sequentially.
     * Skip empty tokens and '.', on '..' pop one directory from the stack if present,
     * otherwise push normal directory names onto the stack.
     * Finally, rebuild the canonical path by joining stack entries with '/' (or return "/" if stack is empty).
     * 
     * Time complexity:
     * O(N)
     *
     * Space complexity:
     * O(N)
     */
    template<>
    std::string Solution<v2>::simplifyPath(std::string path) {
        std::vector<std::string> stack;
        std::stringstream ss(path);
        std::string part;

        while (std::getline(ss, part, '/')) {
            if (part == "" || part == ".") {
                continue;
            }

            if (part == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            }
            else {
                stack.push_back(part);
            }
        }

        if (stack.empty()) {
            return "/";
        }

        std::string result = "";
        for (const std::string& dir : stack) {
            result += "/" + dir;
        }

        return result;
    }

}