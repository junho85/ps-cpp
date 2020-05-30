#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(5);

    for (int num : nums)
        std::cout << num << ' ';

    return 0;
}

