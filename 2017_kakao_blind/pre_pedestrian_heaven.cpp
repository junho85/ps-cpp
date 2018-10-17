#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;

/**
 *
 * @param city_map
 * @param x
 * @param y
 * @param d
 *   0 - start
 *   1 - right
 *   2 - down
 * @return
 *   0 -
 *   1 -
 *   2 - goal
 */

#define ROAD 0
#define NO_ROAD 1
#define ONE_WAY 2

#define NO_WAY 0
#define GOAL 1
/**
 *
 * @param city_map
 * @param x
 * @param y
 * @param d
 * @return success count
 */
int find(vector<vector<int>>* city_map, int x, int y, int d) {
    unsigned long m = (*city_map).size();
    unsigned long n = (*city_map)[0].size();

    int success_count = 0;

    if (x == n-1 && y == m-1) {
        return GOAL;
    }

    if (x < 0 || y < 0 || x >= n || y >= m) {
        return NO_WAY;
    }

    if ((*city_map)[x][y] == NO_ROAD) {
        return NO_WAY;
    }

    if ((*city_map)[x][y] == ROAD) {
        // right
        if (find(city_map, x, y + 1, 1) == GOAL) {
            return GOAL;
        }

        // down
        if (find(city_map, x, y + 1, 2) == GOAL) {
            return GOAL;
        }
    } else if ((*city_map)[x][y] == ONE_WAY) {
        // same direction
        if (find(city_map, x + 1, y, d) == GOAL) {
            return GOAL;
        }
    }

    return success_count;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;

    find(&city_map, 0, 0, 0);

    return answer % MOD;
}

int main() {
    int m = 3;
    int n = 3;
    vector<vector<int>> city_map({
        vector<int>({0, 0, 0}),
        vector<int>({0, 0, 0}),
        vector<int>({0, 0, 0}),
    });

    assert(solution(m, n, city_map) == 6);
    cout << "hello world" << endl;
    return 0;
}