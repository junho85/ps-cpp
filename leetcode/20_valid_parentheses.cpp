// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

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
    bool isValid(string s) {
        stack<char> pstack;
        for (auto c : s) {
            if (c == '(' or c == '[' or c == '{') {
                pstack.push(c);
            } else {
                if (pstack.size() == 0) {
                    return false;
                }
                char left = pstack.top();
                pstack.pop();

                if ((c == ')' and left == '(')
                or (c == ']' and left == '[')
                or (c == '}' and left == '{')) {
                    continue;
                } else {
                    return false;
                }
            }
        }

        if (pstack.size() != 0) {
            return false;
        }

        return true;
    }
};


int main() {
    Solution solution = Solution();

    assert(solution.isValid("()") == true);
    assert(solution.isValid("()[]{}") == true);
    assert(solution.isValid("(]") == false);
    assert(solution.isValid("([)]") == false);
    assert(solution.isValid("{[]}") == true);
    assert(solution.isValid("]") == false); // odd length is false
    assert(solution.isValid("){") == false); // when right side, stack size zero is false
    assert(solution.isValid("[") == false); // after loop, not empty stack means false

    return 0;
}