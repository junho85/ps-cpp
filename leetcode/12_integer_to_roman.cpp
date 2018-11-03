// 12. Integer to Roman
// https://leetcode.com/problems/integer-to-roman/

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

// I 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1000

class Solution {
public:
    string intToRoman(int num) {
        string result;

        string num_string = to_string(num);
        unsigned long length = num_string.size();
        unsigned long level = length;
        for (int i=0; i < length; i++) {

            string one;
            string five;
            string ten;

            if (level == 4) { // 1000
                one = "M";
            } else if (level == 3) { // 100
                one = "C";
                five = "D";
                ten = "M";
            } else if (level == 2) { // 10
                one = "X";
                five = "L";
                ten = "C";
            } else {
                one = "I";
                five = "V";
                ten = "X";
            }

            string roman = "";

            int current_num = num_string[i] - 48; // character to int
            if (current_num >= 1 and current_num <= 3) {
                for (int i=1; i<=current_num; i++) {
                    roman += one;
                }
            } else if (current_num == 4) {
                roman = one + five;
            } else if (current_num == 5) {
                roman = five;
            } else if (current_num >= 6 and current_num <= 8) {
                roman = five;
                for (int i=6; i<=current_num; i++) {
                    roman += one;
                }
            } else if (current_num == 9) {
                roman = one + ten;
            }

            result += roman;

            level--;
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    // input will be 1 to 3999
    assert(solution.intToRoman(3) == "III");
    assert(solution.intToRoman(4) == "IV");
    assert(solution.intToRoman(8) == "VIII");
    assert(solution.intToRoman(9) == "IX");
    assert(solution.intToRoman(10) == "X");
    assert(solution.intToRoman(11) == "XI");
    assert(solution.intToRoman(12) == "XII");
    assert(solution.intToRoman(20) == "XX");
    assert(solution.intToRoman(30) == "XXX");
    assert(solution.intToRoman(40) == "XL");
    assert(solution.intToRoman(50) == "L");
    assert(solution.intToRoman(58) == "LVIII"); // L = 50, V = 5, III = 3
    assert(solution.intToRoman(1994) == "MCMXCIV"); // M = 1000, CM = 900, XC = 90, IV = 4

    return 0;
}