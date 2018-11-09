// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Solution {
private:
    map<char, string> number_map{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
public:
    vector<string> mix(vector<string> left, vector<string> right) {
        vector<string> result;

        for (auto left_it : left) {
            for (auto right_it : right) {
                cout << left_it + right_it << endl;
                result.push_back(left_it + right_it);
            }
        }

        return result;
    }

    vector<string> string_to_vector(string str) {
        vector<string> result;

        for (auto c : str) {
            string tmp;
            tmp.push_back(c);
            result.push_back(tmp);
        }
        return result;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;

        unsigned long length = digits.size();

        for (int i=0; i<length; i++) {
            if (i == 0) {
                result = string_to_vector(number_map[digits[i]]);
            } else {
                result = mix(result, string_to_vector(number_map[digits[i]]));
            }
        }

        return result;
    }

    void print(vector<string>& v) {
        for (auto& str : v) {
            cout << str << endl;
        }
    }
};

int main() {
    Solution solution = Solution();

    auto result = solution.letterCombinations("23");
    solution.print(result);

    result = solution.letterCombinations("2");
    solution.print(result);

    result = solution.letterCombinations("234");
    solution.print(result);

    return 0;
}