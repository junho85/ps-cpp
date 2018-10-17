#include <vector>
#include <iostream>

using namespace std;

void print_picture(vector<vector<int>>* picture) {
    unsigned long m = (*picture).size();
    unsigned long n = (*picture)[0].size();

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cout << (*picture)[i][j];
        }
        cout << endl;
    }
}
int flood_fill_zero(vector<vector<int>>* picture, int x, int y, int current_color) {
    int filled = 0;

    unsigned long m = (*picture).size();
    unsigned long n = (*picture)[0].size();

    if (y < 0 || x < 0 || y >= m || x >= n) {
        return 0;
    }

    if (current_color == 0) {
        return 0;
    }

    if ((*picture)[x][y] == 0) {
        return 0;
    }

    if ((*picture)[x][y] == current_color) {
        (*picture)[x][y] = 0; // fill blank
        filled++;

        print_picture(picture);
        cout << endl;

        filled += flood_fill_zero(picture, x + 1, y, current_color);
        filled += flood_fill_zero(picture, x - 1, y, current_color);
        filled += flood_fill_zero(picture, x, y + 1, current_color);
        filled += flood_fill_zero(picture, x, y - 1, current_color);
    }

    return filled;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            int current_color = picture[i][j];
            int filled = flood_fill_zero(&picture, j, i, current_color);

            if (filled > 0) {
                number_of_area++;
            }

            if (filled > max_size_of_one_area) {
                max_size_of_one_area = filled;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main() {
    int m = 6;
    int n = 4;

    // 4, 5
    vector<vector<int>> picture({
        vector<int>({1, 1, 1, 0}),
        vector<int>({1, 2, 2, 0}),
        vector<int>({1, 0, 0, 1}),
        vector<int>({0, 0, 0, 1}),
        vector<int>({0, 0, 0, 3}),
        vector<int>({0, 0, 0, 3}),
    });

    vector<int> answer;

    answer = solution(m, n, picture);

    cout << answer[0] << answer[1] << endl;

    return 0;
}