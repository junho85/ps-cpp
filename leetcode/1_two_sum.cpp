#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer(2);

        int right = nums[1];

        unsigned long length = nums.size();
        for (int i = 0; i < length; i++) {
            int left = nums[i];

            for (int j=i+1; j<length; j++) {
                if (left + nums[j] == target) {
                    answer[0] = i;
                    answer[1] = j;
                    return answer;
                }
            }
        }
    }
};

int main() {
//    vector<int> nums({2,7,11,15});
    vector<int> nums({3,2,4});

    Solution solution = Solution();
//    vector<int> answer = solution.twoSum(nums, 9);
    vector<int> answer = solution.twoSum(nums, 6);

    cout << answer[0] << ":" << answer[1] << endl;
    return 0;
}