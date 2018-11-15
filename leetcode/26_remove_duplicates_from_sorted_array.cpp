// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

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
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};


int main() {
    Solution solution = Solution();

    vector<int> nums1({1,1,2});
    assert(solution.removeDuplicates(nums1) == 2);

    vector<int> nums2({0,0,1,1,1,2,2,3,3,4});
    assert(solution.removeDuplicates(nums2) == 5);

    return 0;
}