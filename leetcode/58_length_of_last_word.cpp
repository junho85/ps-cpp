// 58. Length of Last Word
// https://leetcode.com/problems/length-of-last-word/

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
    int lengthOfLastWord(string s) {
        unsigned long length = s.size();
        if (length == 0) {
            return 0;
        }

        bool is_triming = true;
        int result = 0;
        for (long i=length-1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (is_triming) {
                    continue;
                }
                return result;
            } else {
                is_triming = false;
                result++;
            }
        }

        return result;
    }
};

int main() {

    Solution solution = Solution();

    assert(solution.lengthOfLastWord("Hello World") == 5);
    assert(solution.lengthOfLastWord("a") == 1);
    assert(solution.lengthOfLastWord("a ") == 1);

    return 0;
}

