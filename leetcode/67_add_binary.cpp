// 67. Add Binary
// https://leetcode.com/problems/add-binary/submissions/

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        unsigned long max_length = max(a.size(), b.size());

        string result;

        bool is_up = false;

        for (int i = 0; i < max_length; i++) {
            int current = 0;
            if (is_up) {
                current++;
                is_up = false;
            }

            char a_last = '0';
            if (!a.empty()) {
                a_last = a.back();

                if (a_last == '1') current++;
                a.pop_back();
            }

            char b_last = '0';
            if (!b.empty()) {
                b_last = b.back();

                if (b_last == '1') current++;
                b.pop_back();
            }

            if (current >= 2) {
                is_up = true;
                current %= 2;
            }

            if (current == 0) {
                result = '0' + result;
            } else {
                result = '1' + result;
            }
        }

        if (is_up) {
            result = '1' + result;
        }

        return result;
    }
};

int main() {
    Solution solution = Solution();

    assert(solution.addBinary("11", "1") == "100");
    assert(solution.addBinary("1010", "1011") == "10101");

    assert(solution.addBinary("10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101", "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011") == "110111101100010011000101110110100000011101000101011001000011011000001100011110011010010011000000000");
    assert(solution.addBinary("1", "111") == "1000");

    return 0;
}

