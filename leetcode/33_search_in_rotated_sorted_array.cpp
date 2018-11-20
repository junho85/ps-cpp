// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

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
    int search(vector<int>& nums, int target) {
        ptrdiff_t pos = distance(nums.begin(), find(nums.begin(), nums.end(), target));
        if (pos == -1 or pos == nums.size()) {
            return -1;
        } else {
            return pos;
        }
    }
};

int main() {
    Solution solution = Solution();

    vector<int> input1({4,5,6,7,0,1,2});
    assert(solution.search(input1, 0) == 4);
    assert(solution.search(input1, 3) == -1);

    return 0;
}