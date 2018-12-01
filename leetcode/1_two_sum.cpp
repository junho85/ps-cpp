#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer(2);

        map<int, int> map_nums; // number, index

        // put into map
        auto length = nums.size();
        for (int i=0; i<length; i++) {
            map_nums[nums[i]] = i;
        }

        for (int i = 0; i < length; i++) {
            int find_num = target - nums[i];
            auto iter = map_nums.find(find_num);

            if (iter != map_nums.end() && iter->second != i) {
                answer[0] = i;
                answer[1] = iter->second;
                return answer;
            }
        }
        return answer;
    }

    vector<int> twoSum_old(vector<int>& nums, int target) {
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
        return answer;
    }
};


int main() {
    vector<int> nums({2,7,11,15});

    Solution solution = Solution();
    vector<int> answer = solution.twoSum(nums, 9);
    cout << answer[0] << ":" << answer[1] << endl;

    nums.clear();
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    answer = solution.twoSum(nums, 6);

    cout << answer[0] << ":" << answer[1] << endl;
    return 0;
}