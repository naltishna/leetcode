#include "68_text_justification.h"

namespace _68 {

    /*
    * Greedy Packing: It packs as many words as possible into the current line, ensuring there is at least one space between them (length + 1).
    * 
    * Space Distribution (Justification):
    * Normal Lines: It calculates the remaining gaps and distributes spaces evenly using modular arithmetic (total / gaps and total % gaps).
    * Last Line / Single Word: It left-justifies the text (adds only 1 space between words and fills the remainder with trailing spaces).
    * 
    * Time complexity:
    * O(N), where N is the total number of characters in the words array.
    * 
    * Space complexity:
    * O(N) (excluding the result vector) to store the lineWords temporary buffer.
    */
    std::vector<std::string> Solution::fullJustify(std::vector<std::string>& words, int maxWidth) {
        int n = words.size();
        int lineLen = maxWidth;

        std::vector<std::string> output;
        std::vector<std::string> lineWords;

        for (int i = 0; i < n; ++i) {
            std::string str = words[i];
            lineLen -= static_cast<int>(str.size());

            int lineWordCount = lineWords.size();
            if ((lineLen - static_cast<int>(lineWordCount)) >= 0) {
                lineWords.push_back(str);
            } else {
                lineLen += static_cast<int>(str.size());

                // A line with N words has N - 1 gaps where spaces can be distributed.
                int betweenWordGaps = static_cast<int>(lineWordCount) - 1;
                int base_spaces = (betweenWordGaps > 0) ? (lineLen / betweenWordGaps) : lineLen;
                int extra_spaces = (betweenWordGaps > 0) ? (lineLen % betweenWordGaps) : 0;

                std::string line;
                line.reserve(maxWidth);

                for (int i = 0; i < lineWordCount; ++i) {
                    line += lineWords[i];

                    // Spaces are inserted only between words; the last word has no trailing gap.
                    if (i < betweenWordGaps) {
                        int current_spaces = base_spaces + ((i < extra_spaces) ? 1 : 0);
                        line.append(current_spaces, ' ');
                    }
                }

                if (betweenWordGaps == 0) {
                    line.append(maxWidth - static_cast<int>(line.size()), ' ');
                }

                output.push_back(line);
                lineWords.clear();
                lineLen = maxWidth;
                --i;
            }
        }

        if (!lineWords.empty()) {
            std::string line;
            line.reserve(maxWidth);

            for (int i = 0; i < lineWords.size(); ++i) {
                line += lineWords[i];

                if (i < lineWords.size() - 1) {
                    line.append(1, ' ');
                }
                else {
                    line.append(maxWidth - static_cast<int>(line.size()), ' ');
                }
            }

            output.push_back(line);
        }
        
        return output;
    }

}