// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

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
    map<int, int> result_map{
            {1, 1},
            {2, 2},
            {3, 3},
            {4, 5},
            {5, 8},
            {6, 13},
    };

public:
    int climbStairs(int n) {
        if (result_map.find(n) != result_map.end()) {
            return result_map[n];
        } else {
            // not found

            // get answer
            int result = climbStairs(n-1) + climbStairs(n-2);
            result_map[n] = result;
            return result;
        }
    }
};

int main() {

    Solution solution = Solution();

    assert(solution.climbStairs(1) == 1);
    assert(solution.climbStairs(2) == 2);
    assert(solution.climbStairs(3) == 3);
    assert(solution.climbStairs(4) == 5);
    assert(solution.climbStairs(5) == 8);
    assert(solution.climbStairs(6) == 13);

    return 0;
}

