#include "6_zigzag_conversion.h"

#include <vector>

namespace _6 {

    /*
    * Iterate through the string, distributing characters into rows by moving a pointer up and down.
    * Finally, concatenate all rows to get the result.
    * 
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(N)
    */
    std::string Solution::convert(std::string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) {
            return s;
        }

        std::vector<std::string> rows(numRows);
        int currentRow = 0;
        bool goDown = false;

        for (char c : s) {
            rows[currentRow] += c;

            if (currentRow == 0 || currentRow == numRows - 1) {
                goDown = !goDown;
            }

            currentRow += goDown ? 1 : -1; // Move down or up
        }

        std::string result;

        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }

}