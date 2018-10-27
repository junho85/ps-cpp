#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool is_minus = false;
        if (x < 0) {
            is_minus = true;
            x *= -1;
        }

        int result = 0;
        while (x > 0) {
            int num = x % 10;
            int prev = result;
            if (result != 0) {
                // check overflow
                if (long(result) * 10 > INT_MAX) {
                    return 0;
                }
                result *= 10;
            }

            result += num;

            x /= 10;
        }
        if (is_minus) {
            result *= -1;
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
//    assert(solution.reverse(123) == 321);
//    assert(solution.reverse(-123) == -321);
//    assert(solution.reverse(120) == 21);
    assert(solution.reverse(1534236469) == 0);

    return 0;
}