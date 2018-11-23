// 35. Search Insert Position
// https://leetcode.com/problems/search-insert-position/submissions/

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
    int searchInsert(vector<int>& nums, int target) {
        auto low = lower_bound(nums.begin(), nums.end(), target);
        return low - nums.begin();
    }
};

int main() {

    Solution solution = Solution();

    vector<int> input1({1,3,5,6});
    assert(solution.searchInsert(input1, 5) == 2);
    assert(solution.searchInsert(input1, 2) == 1);
    return 0;
}