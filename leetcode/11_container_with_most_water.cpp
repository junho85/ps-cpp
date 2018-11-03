// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;

        unsigned long length = height.size();
        for (int i=0; i < length - 1; i++) {
            int first_height = height[i];
            for (int j=i+1; j<length; j++) {
                int second_height = height[j];
                int width = j-i;
                int height = min(first_height, second_height);
                int water = height * width;
                if (water > max) {
                    max = water;
                }
            }
        }
        return max;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> nums({1,8,6,2,5,4,8,3,7});
    assert(solution.maxArea(nums) == 49);

    return 0;
}