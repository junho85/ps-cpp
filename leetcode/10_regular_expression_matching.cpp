// 10. Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <regex>

using namespace std;

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.

class Solution {
public:
    bool isMatch(string s, string p) {
        return false;
    }
};

int main() {
    Solution solution = Solution();
    assert(solution.isMatch("aa", "a") == false);
    assert(solution.isMatch("aa", "a*") == true);
    assert(solution.isMatch("ab", ".*") == true);
    assert(solution.isMatch("aab", "c*a*b") == true);

    assert(solution.isMatch("mississippi", "mis*is*p*.") == false);
    assert(solution.isMatch("ab", ".*c") == false);
    assert(solution.isMatch("aaa", "a*a") == true);
    assert(solution.isMatch("aaa", "ab*a*c*a") == true);
    return 0;
}