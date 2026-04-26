#include "67_add_binary.h"
#include "class_version.h"

namespace _67 {

    /*
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(n)
    */
    template<>
    std::string Solution<ver1>::addBinary(std::string a, std::string b) {
        std::string result;
        int carry = 0;
        int i = static_cast<int>(a.size()) - 1;
        int j = static_cast<int>(b.size()) - 1;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';
                --i;
            }

            if (j >= 0) {
                sum += b[j] - '0';
                --j;
            }

            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        std::reverse(result.begin(), result.end());
        
        return result;
    }

    /*
    * stoull is limited to 64 bits, so it can handle binary strings up to 64 characters long.
    * For longer strings, this approach would fail.
    * 
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    std::string Solution<ver2>::addBinary(std::string a, std::string b) {
        unsigned long long numA = std::stoull(a, nullptr, 2);
        unsigned long long numB = std::stoull(b, nullptr, 2);

        unsigned long long sum = numA + numB;

        if (sum == 0) {
            return "0";
        }

        std::string result;
        while (sum > 0) {
            int d = sum & 1;
            int c = d + '0';
            result.push_back((sum & 1) + '0');
            sum >>= 1;
        }

        std::reverse(result.begin(), result.end());

        return result;
    }

    /*
    * Iterates both strings from the least significant bit to the most significant, computing sum = digitA + digitB + carry at each step,
    * extracting the current bit via sum & 1 and the new carry via sum >> 1. The result reverses at the end.
    * 
    * Time complexity:
    * O(n)
    * 
    * Space complexity:
    * O(n)
    */
    template<>
    std::string Solution<ver3>::addBinary(std::string a, std::string b) {
        int i = static_cast<int>(a.size()) - 1;
        int j = static_cast<int>(b.size()) - 1;
        int carry = 0;

        std::string result;
        result.reserve(std::max(a.size(), b.size()) + 1);

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';
                --i;
            }

            if (j >= 0) {
                sum += b[j] - '0';
                --j;
            }

            result.push_back(static_cast<char>((sum & 1) + '0'));
            carry = sum >> 1;
        }

        std::reverse(result.begin(), result.end());

        return result;
    }

}