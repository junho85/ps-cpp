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
        int max_length = max(a.size(), b.size());
        long long sum = stoll(a, nullptr, 2) + stoll(b, nullptr, 2);

        string result;
        while (sum != 0) {
            if (sum % 2 == 0) {
                result = "0" + result;
            } else {
                result = "1" + result;
            }
            sum /= 2;
        }
        return result;
    }
};

int main() {

    Solution solution = Solution();

    assert(solution.addBinary("11", "1") == "100");
    assert(solution.addBinary("1010", "1011") == "10101");

    assert(solution.addBinary("10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101", "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011") == "");

    return 0;
}

