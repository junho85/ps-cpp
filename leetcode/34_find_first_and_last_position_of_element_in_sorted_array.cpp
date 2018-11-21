// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;

        ptrdiff_t pos1 = distance(nums.begin(), find(nums.begin(), nums.end(), target));
        if (pos1 == -1 or pos1 == nums.size()) {
            result.push_back(-1);
            result.push_back(-1);
        } else {
            result.push_back(pos1);

            ptrdiff_t pos2 = distance(find(nums.rbegin(), nums.rend(), target), nums.rend()) - 1;
            result.push_back(pos2);
        }

        return result;
    }

    void print(vector<int> vec) {
        for (auto it : vec) {
            cout << it << " ";
        }
        cout << endl;
    }
};

int main() {

    Solution solution = Solution();

    vector<int> input1({5,7,7,8,8,10});
    auto result = solution.searchRange(input1, 8);
    solution.print(result);
    return 0;
}