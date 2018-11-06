// 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string result = strs[0];

        for (vector<string>::iterator it = strs.begin() + 1; it<strs.end(); ++it) {

            for (int i=0; i<result.size(); i++) {
                if (result[i] != (*it)[i]) {
                    if (i == 0) {
                        return "";
                    } else {
                        result = result.substr(0, i);
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();

    vector<string> input1({"flower","flow","flight"});
    assert(solution.longestCommonPrefix(input1) == "fl");
    vector<string> input2({"dog","racecar","car"});
    assert(solution.longestCommonPrefix(input2) == "");
    vector<string> input3({});
    assert(solution.longestCommonPrefix(input3) == "");

    return 0;
}