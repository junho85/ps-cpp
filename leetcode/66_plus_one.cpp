// 66. Plus One
// https://leetcode.com/problems/plus-one/

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
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        int i;
        for (i=length-1; i>=0; i--) {
            digits[i]++;
            if (digits[i] != 10) {
                return digits;
            }
            digits[i] = 0;
        }
        if (digits[0] == 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main() {

    Solution solution = Solution();

    vector<int> input1({1,2,3});
    auto result = solution.plusOne(input1);
    for (auto it : result) {
        cout << it << endl;
    }
    cout << endl;

    vector<int> input2({9});
    result = solution.plusOne(input2);
    for (auto it : result) {
        cout << it << endl;
    }

    return 0;
}

