// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

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
    vector<string> letterCombinations(string digits) {
        vector<string> result({"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"});
        return result;
    }

    void print(vector<string>& v) {
        for (auto& str : v) {
            cout << str << endl;
        }
    }
};

int main() {
    Solution solution = Solution();

    auto result = solution.letterCombinations("23");
    solution.print(result);

    return 0;
}