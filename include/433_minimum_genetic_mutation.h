/*
https://leetcode.com/problems/minimum-genetic-mutation/description/

433. Minimum Genetic Mutation

A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation
is defined as one letter changed in the gene string.

All gene strings must be valid and each mutation must come from the bank.

Given the two gene strings startGene and endGene and the bank, return the minimum number of mutations needed to mutate
from startGene to endGene. If there is no such a mutation, return -1.

Note that the initial gene and end gene are not required to be in the bank.

Example 1:
Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1

Example 2:
Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2

Example 3:
Input: startGene = "AAAAACCC", endGene = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
Output: 3

Constraints:
startGene.length == 8
endGene.length == 8
0 <= bank.length <= 10
bank[i].length == 8
startGene, endGene, and bank[i] consist of only the characters ["A","C","G","T"].
*/

#pragma once

#include "class_version.h"
#include <string>
#include <vector>

namespace _433 {

    template <class V>
    class Solution {
    public:
        int minMutation(const std::string& startGene,
                        const std::string& endGene,
                        const std::vector<std::string>& bank);
    };

}
