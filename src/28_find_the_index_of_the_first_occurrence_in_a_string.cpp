#include "28_find_the_index_of_the_first_occurrence_in_a_string.h"
#include "class_version.h"

#include <vector>

namespace _28 {

    /*
    * The solution works but it is not optimal.
    *
    * Time complexity:
    * O(m * n), where m is the length of the string needle, n is the length of the string haystack
    *
    * Space complexity:
    * O(1)
    */
    int Solution<v1>::strStr(std::string haystack, std::string needle) {
        if (needle.empty()) return 0;

        int pos = -1;

        if (needle.size() > haystack.size()) {
            return pos;
        }

        int i = 0;
        for (int j = 0; i < needle.size() && j < haystack.size();) {
            if (needle[i] == haystack[j]) {
                if (pos == -1) {
                    pos = j;
                }
                i++;
                j++;
            }
            else if (i > 0) {
                i = 0;
                j = pos + 1;
                pos = -1;
            }
            else {
                j++;
            }
        }

        return i == needle.size() ? pos : -1;
    }

    /*
    * The solution with early exit is suitable for short strings.
    *
    * Note: It is better to use the KMP algorithm (Knuth-Morris-Pratt) for large texts with repeats.
    *
    * Time complexity:
    * O(m * n), where m is the length of the string needle, n is the length of the string haystack
    *
    * Space complexity:
    * O(1)
    */
    int Solution<v2>::strStr(std::string haystack, std::string needle) {
        if (needle.empty()) return 0;
        if (needle.size() > haystack.size()) return -1;

        int limit = haystack.size() - needle.size();
        for (int i = 0; i <= limit; ++i) {
            int j = 0;
            while (j < needle.size() && haystack[i + j] == needle[j]) {
                j++;
            }

            if (j == needle.size()) return i;
        }

        return -1;
    }

    /*
    * KMP algorithm (Knuth-Morris-Pratt) for large texts with repeats.
    *
    * Time complexity:
    * O(n + m), where m is the length of the string needle, n is the length of the string haystack
    *
    * Space complexity:
    * O(m), where m is the length of the string needle.
    */
    int Solution<v3>::strStr(std::string haystack, std::string needle) {
        if (needle.empty()) return 0;
        if (needle.size() > haystack.size()) return -1;

        int m = needle.size();
        std::vector<int> lps(m, 0); // Longest proper prefix

        for (int i = 1, length = 0; i < m;) {
            if (needle[i] == needle[length]) {
                lps[i++] = ++length;
            }
            else if (length > 0) {
                length = lps[length - 1];
            }
            else {
                lps[i++] = 0;
            }
        }

        for (int i = 0, j = 0; i < haystack.size();) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;

                if (j == m) {
                    return i - j;
                }
            }
            else if (j > 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }

        return -1;
    }

    /*
    * Use STL.
    *
    * Time complexity:
    * O(m + n), where m is the length of the string needle, n is the length of the string haystack
    *
    * Space complexity:
    * O(N)
    */
    int Solution<v4>::strStr(std::string haystack, std::string needle) {
        if (needle.empty()) return 0;

        size_t pos = haystack.find(needle);

        return pos != std::string::npos ? static_cast<int>(pos) : -1;
    }

}