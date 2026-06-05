#include "433_minimum_genetic_mutation.h"
#include "class_version.h"

#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

namespace _433 {

    /*
    * Check if two genes differ by exactly one character.
    */
    static bool differsByOne(const std::string& left, const std::string& right) {
        int diff = 0;

        for (size_t i = 0; i < left.size(); ++i) {
            if (left[i] != right[i]) {
                ++diff;
            }

            if (diff > 1) {
                return false;
            }
        }

        return diff == 1;
    }

    /*
    * Check if the start gene is the same as the end gene or if the end gene is not in the bank.
    */
    static int impossibleIfNeeded(const std::string& startGene, const std::string& endGene,
        const std::unordered_set<std::string>& bankSet) {
        // If the start gene is the same as the end gene, no mutations are needed.
        if (startGene == endGene) {
            return 0;
        }

        // If the end gene is not in the bank, it is impossible to mutate to it.
        if (!bankSet.contains(endGene)) {
            return -1;
        }

        // If the start gene is not the same as the end gene and the end gene is in the bank,
        // it is possible to mutate to it, but we need to check if there is a path to it.
        return -2;
    }

    /*
    * Approach: BFS over bank genes.
    *
    * From the current gene, try every unused bank gene that differs by exactly one character.
    *
    * Time complexity:
    * O(B^2 * L), where B is bank size and L is gene length
    *
    * Space complexity:
    * O(B)
    */
    template<>
    int Solution<ver1>::minMutation(const std::string& startGene,
        const std::string& endGene,
        const std::vector<std::string>& bank) {
        std::unordered_set<std::string> bankSet(bank.begin(), bank.end());

        // Check if the start gene is the same as the end gene or if the end gene is not in the bank.
        const int ready = impossibleIfNeeded(startGene, endGene, bankSet);
        if (ready != -2) {
            return ready;
        }

        std::vector<bool> used(bank.size(), false);
        std::queue<std::pair<std::string, int>> q;
        q.push({ startGene, 0 });

        while (!q.empty()) {
            const auto [gene, steps] = q.front();
            q.pop();

            for (size_t i = 0; i < bank.size(); ++i) {
                if (used[i] || !differsByOne(gene, bank[i])) {
                    continue;
                }

                used[i] = true;
                const int nextSteps = steps + 1;

                if (bank[i] == endGene) {
                    return nextSteps;
                }

                q.push({ bank[i], nextSteps });
            }
        }

        return -1;
    }

    /*
    * Approach: BFS with generated neighbors.
    *
    * Models mutations as a graph where each valid gene is a node.
    * BFS finds the minimum number of mutations to reach endGene.
    * At each step change one character to A/C/G/T and continue only if the result is in the bank.
    *
    * Time complexity:
    * O(B * L * 4), where B is bank size and L is gene length, 4 is the number of possible letters.
    *
    * Space complexity:
    * O(B)
    */
    template<>
    int Solution<ver2>::minMutation(const std::string& startGene,
        const std::string& endGene,
        const std::vector<std::string>& bank) {
        std::unordered_set<std::string> bankSet(bank.begin(), bank.end());

        // Check if the start gene is the same as the end gene or if the end gene is not in the bank.
        const int ready = impossibleIfNeeded(startGene, endGene, bankSet);
        if (ready != -2) {
            return ready;
        }

        std::unordered_set<std::string> visited{ startGene };
        std::queue<std::pair<std::string, int>> q;
        q.push({ startGene, 0 });

        const std::string letters = "ACGT";

        while (!q.empty()) {
            const auto [gene, steps] = q.front();
            q.pop();

            for (size_t i = 0; i < gene.size(); ++i) {
                std::string next = gene;

                for (char letter : letters) {
                    if (letter == gene[i]) {
                        continue;
                    }

                    next[i] = letter;

                    if (!bankSet.contains(next)) {
                        continue;
                    }

                    if (next == endGene) {
                        return steps + 1;
                    }

                    if (visited.contains(next)) {
                        continue;
                    }

                    visited.insert(next);
                    q.push({ next, steps + 1 });
                }
            }
        }

        return -1;
    }

}
