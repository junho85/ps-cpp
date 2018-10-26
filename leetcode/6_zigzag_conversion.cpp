// 6. ZigZag Conversion

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        bool direction = true; // true - down, false - up
        int row = 0;
        unsigned long length = s.size();
        vector<string> tmp(min(numRows, int(length)));
        for (int i=0; i < length; i++) {
            tmp[row] += s[i];

            if (direction) {
                row++;
            } else {
                row--;
            }

            if (row == 0 or row == numRows - 1) {
                direction = !direction;
            }
        }

        string result;
        int loop = min(numRows, int(length));
        for (int i=0; i<loop; i++) {
            result += tmp[i];
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    assert(solution.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    assert(solution.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    assert(solution.convert("AB", 1) == "AB");
    return 0;
}