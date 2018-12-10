// 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/

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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.begin() + m, nums1.end());
        nums1.insert(nums1.begin(), nums2.begin(), nums2.begin() + n);
        sort(nums1.begin(), nums1.end());
    }
};

int main() {
    Solution solution = Solution();

    vector<int> nums1({1,2,3,0,0,0});
    vector<int> nums2({2,5,6});

    solution.merge(nums1, 3, nums2, 3);

    for (auto num : nums1) {
        cout << num << endl;
    }

    return 0;
}

