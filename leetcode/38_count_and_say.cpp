// 38. Count and Say
// https://leetcode.com/problems/count-and-say/

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
    map<int, string> result_map{
            {1, "1"},
            {2, "11"},
            {3, "21"},
            {4, "1211"},
            {5, "111221"},
    };

public:
    string countAndSay(int n) {
        if (result_map.find(n) != result_map.end()) {
            return result_map[n];
        } else {
            // not found

            // get before
            string before = countAndSay(n-1);

            string result;

            int length = before.size();

            int count;
            char prev = NULL;

            for (int i=0; i<length; i++) {
                char cur = before[i];
                if (i == 0) {
                    count = 1;
                    prev = cur;
                } else {
                    if (prev == cur) {
                        count++;

                        // is end?
                        if (i + 1 == length) {
                            result += (to_string(count) + prev);
                            break;
                        }

                    } else {
                        // different
                        result += (to_string(count) + prev);

                        count = 1;
                        prev = cur;

                        // is end?
                        if (i + 1 == length) {
                            result += (to_string(count) + prev);
                            break;
                        }
                    }
                }
            }

            result_map[n] = result;

//            cout << "result=" << result << endl;
            return result;
        }
    }
};

int main() {

    Solution solution = Solution();

    assert(solution.countAndSay(1) == "1");
    assert(solution.countAndSay(4) == "1211");
    assert(solution.countAndSay(5) == "111221");

    return 0;
}