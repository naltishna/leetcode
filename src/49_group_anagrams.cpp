#include "49_group_anagrams.h"
#include "class_version.h"

#include <algorithm>
#include <array>
#include <unordered_map>

namespace _49 {

    /*
    * Group anagrams by sorting each string alphabetically.
    * Store groups in a hash map {sortedKey → [words]}, then collect values into the result.
    * 
    * Time complexity:
    * O(NKlogK), where n is the number of lines; k is the maximum line length
    * 
    * Space complexity:
    * O(NK)
    */
    std::vector<std::vector<std::string>> Solution::groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagramGroups;

        for (const auto& str : strs) {
            std::string sortedStr = str;
            std::sort(sortedStr.begin(), sortedStr.end());
            anagramGroups[sortedStr].push_back(str);
        }

        std::vector<std::vector<std::string>> result;
        result.reserve(anagramGroups.size());

        for (auto& [key, group] : anagramGroups) {
            result.push_back(std::move(group));
        }

        return result;
    }

}