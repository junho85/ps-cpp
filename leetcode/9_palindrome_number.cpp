// 9. Palindrome Number
// https://leetcode.com/problems/palindrome-number/

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);

        unsigned long half_size = s.size()/2;

        string left = s.substr(0, half_size);
        string right = s.substr(half_size + (s.size()%2 == 1 ? 1 : 0));
        reverse(right.begin(), right.end());

        if (left == right) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution solution = Solution();
    assert(solution.isPalindrome(121) == true);
    assert(solution.isPalindrome(-121) == false);
    assert(solution.isPalindrome(10) == false);
    return 0;
}