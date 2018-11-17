// 28. Implement strStr()
// https://leetcode.com/problems/implement-strstr/

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
    int strStr(string haystack, string needle) {
        return haystack.find(needle, 0);
    }
};

int main() {
    Solution solution = Solution();

    assert(solution.strStr("hello", "ll") == 2);
    assert(solution.strStr("aaaaa", "bba") == -1);

    return 0;
}