// 29. Divide Two Integers
// https://leetcode.com/problems/divide-two-integers/

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long result = long(dividend)/long(divisor);

        if (result < INT_MIN) {
            return INT_MIN;
        } else if (result > INT_MAX) {
            return INT_MAX;
        }

        return result;
    }
};

int main() {
    Solution solution = Solution();

    assert(solution.divide(10, 3) == 3);
    assert(solution.divide(7, -3) == -2);
    assert(solution.divide(-2147483648, -1) == INT_MAX);

    return 0;
}