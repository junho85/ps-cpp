// 69. Sqrt(x)
// https://leetcode.com/problems/sqrtx/

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <math.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        return sqrt(x);
    }
};

int main() {

    Solution solution = Solution();

    assert(solution.mySqrt(4) == 2);
    assert(solution.mySqrt(8) == 2);

    return 0;
}

