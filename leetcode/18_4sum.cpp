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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

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

    return 0;
}