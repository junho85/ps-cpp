// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        char prev_char = NULL;
        for (int i=0; i<s.size(); i++) {
            char current_char = s[i];
            if (current_char == 'I') {
                result++;
            } else if (current_char == 'V') {
                result += 5;
                if (prev_char == 'I') {
                    result -= 2;
                }
            } else if (current_char == 'X') {
                result += 10;
                if (prev_char == 'I') {
                    result -= 2;
                }
            } else if (current_char == 'L') {
                result += 50;
                if (prev_char == 'X') {
                    result -= 20;
                }
            } else if (current_char == 'C') {
                result += 100;
                if (prev_char == 'X') {
                    result -= 20;
                }
            } else if (current_char == 'D') {
                result += 500;
                if (prev_char == 'C') {
                    result -= 200;
                }
            } else if (current_char == 'M') {
                result += 1000;
                if (prev_char == 'C') {
                    result -= 200;
                }
            }
            prev_char = current_char;
        }
        cout << result << endl;
        return result;
    }
};

int main() {
    Solution solution = Solution();
    // input will be 1 to 3999
    assert(solution.romanToInt("III") == 3);
    assert(solution.romanToInt("IV") == 4);
    assert(solution.romanToInt("VIII") == 8);
    assert(solution.romanToInt("IX") == 9);
    assert(solution.romanToInt("X") == 10);
    assert(solution.romanToInt("XI") == 11);
    assert(solution.romanToInt("XII") == 12);
    assert(solution.romanToInt("XX") == 20);
    assert(solution.romanToInt("XXX") == 30);
    assert(solution.romanToInt("XL") == 40);
    assert(solution.romanToInt("L") == 50);
    assert(solution.romanToInt("LVIII") == 58); // L = 50, V = 5, III = 3
    assert(solution.romanToInt("MCDLXXVI") == 1476);
    assert(solution.romanToInt("MCMXCIV") == 1994); // M = 1000, CM = 900, XC = 90, IV = 4

    return 0;
}