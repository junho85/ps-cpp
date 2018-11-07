// 16. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        return 1;
    }
};

int main() {
    Solution solution = Solution();

    vector<int> input1({-1, 2, 1, -4});
    assert(solution.threeSumClosest(input1, 1) == 1);

    return 0;
}