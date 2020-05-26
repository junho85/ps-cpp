#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; ++i) {
        int merged = arr1[i] | arr2[i];

        string tmp;
        for (int j = 0; j < n; ++j) {
            if (((merged >> j) & 1) == 1) {
                tmp = "#" + tmp;
            } else {
                tmp = " " + tmp;
            }
        }
        answer.emplace_back(tmp);
    }

    return answer;
}

int main() {
    vector<int> arr1({9, 20, 28, 18, 11});
    vector<int> arr2({30, 1, 21, 17, 28});

    vector<string> answer = solution(5, arr1, arr2);

    for (auto it = answer.begin(); it<answer.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}