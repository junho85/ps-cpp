// 8. String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/
// easy way. use atol and check INT_MIN and INT_MAX

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long t = atol(str.c_str());
        if (t < INT_MIN) {
            return INT_MIN;
        } else if (t > INT_MAX) {
            return INT_MAX;
        }
        return int(t);
    }
};

int main() {
    Solution solution = Solution();
    assert(solution.myAtoi("42") == 42);
    assert(solution.myAtoi("4193 with words") == 4193);
    assert(solution.myAtoi("-91283472332") == -2147483648);
    assert(solution.myAtoi("2147483648") == 2147483647);
    return 0;
}