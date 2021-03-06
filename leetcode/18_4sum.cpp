// 18. 4Sum
// https://leetcode.com/problems/4sum/

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
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        set<vector<int>> temp_result;
        sort(nums.begin(), nums.end());

        unsigned long length = nums.size();
        if (length < 4) {
            vector<vector<int>> result;
            return result;
        }

        for (int i = 0; i < length - 3; i++) {
            if (i + 4 < length and nums[i] == nums[i + 4]) {
                continue;
            }
            for (int j = i + 1; j < length - 2; j++) {
                int pre_sum = nums[i] + nums[j];

                for (int k = j + 1; k < length - 1; k++) {
                    int pre_sum2 = pre_sum + nums[k];
                    int find = target - pre_sum2;

                    auto low = lower_bound(nums.begin() + k + 1, nums.end(), find);

                    if (low != nums.end() && !(find < *low)) {
                        vector<int> row({nums[i], nums[j], nums[k], nums[low - nums.begin()]});
                        temp_result.insert(row);
                    }
                }
            }
        }
        vector<vector<int>> result(temp_result.begin(), temp_result.end());
        return result;
    }

    void printVector(vector<vector<int>> &result) {
        cout << "start" << endl;
        cout << result.size() << endl;
        for (auto row : result) {
            for (int j : row) {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    Solution solution = Solution();

    vector<int> input1({1, 0, -1, 0, -2, 2});
    auto result = solution.fourSum(input1, 0);
    solution.printVector(result);
    assert(result.size() == 3);

    vector<int> input2({0, 0, 0, 0});
    result = solution.fourSum(input2, 0);
    solution.printVector(result);
    assert(result.size() == 1);

    vector<int> input3({0, 0, 0, 0});
    result = solution.fourSum(input3, 1);
    solution.printVector(result);
    assert(result.size() == 0);

    return 0;
}