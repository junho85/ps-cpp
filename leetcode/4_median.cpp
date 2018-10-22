#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());

        int center = (int)(nums1.size()/2);
        if (nums1.size() % 2 == 0) {
            return (double)(nums1[center-1] + nums1[center])/2;
        } else {
            return nums1[center];
        }
    }
};

int main() {
    Solution solution = Solution();

    vector<int> nums1({1,3});
    vector<int> nums2({2});

    assert(solution.findMedianSortedArrays(nums1, nums2) == 2.0);

    vector<int> nums3({1,2});
    vector<int> nums4({3,4});
    double ret2 = solution.findMedianSortedArrays(nums3, nums4);
    cout << ret2 << endl;
    assert(ret2 == 2.5);

    return 0;
}