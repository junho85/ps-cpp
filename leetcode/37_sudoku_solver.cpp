// 37. Sudoku Solver
// https://leetcode.com/problems/sudoku-solver/

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
public:
    void solveSudoku(vector<vector<char>>& board) {

    }

    bool isValidSudoku(vector<vector<char>>& board) {
        unsigned long length = 9;
        for (int i=0; i<length; i++) {

            set<char> row_check;
            set<char> col_check;

            for (int j=0; j<length; j++) {
                // row check
                auto row_item = board[i][j];

                if (row_item != '.') {
                    auto ret = row_check.insert(row_item);

                    if (ret.second == false) {
                        return false;
                    }
                }

                // col check
                auto col_item = board[j][i];
                if (col_item != '.') {
                    auto ret = col_check.insert(col_item);

                    if (ret.second == false) {
                        return false;
                    }
                }
            }
        }

        // sub box check
        // 00 01 02   03 04 05   06 07 08
        // 10 11 12   13 14 15   16 17 18
        // 20 21 22   23 24 25   26 27 28
        //
        // 30 31 32   33 34 35   36 37 38

        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
//                cout << "=== " << j << " " << i << " " << endl;
                set<char> sub_box_check;
                for (int k=0; k<3; k++) {
                    for (int l=0; l<3; l++) {
                        int a = i*3+k;
                        int b = j*3+l;
//                        cout << a << " " << b << " " << endl;

                        auto item = board[b][a];
                        if (item != '.') {
                            auto ret = sub_box_check.insert(item);

                            if (ret.second == false) {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main() {

    Solution solution = Solution();

    vector<vector<char>> input1({
                                        vector<char>({'5','3','.','.','7','.','.','.','.'}),
                                        vector<char>({'6','.','.','1','9','5','.','.','.'}),
                                        vector<char>({'.','9','8','.','.','.','.','6','.'}),
                                        vector<char>({'8','.','.','.','6','.','.','.','3'}),
                                        vector<char>({'4','.','.','8','.','3','.','.','1'}),
                                        vector<char>({'7','.','.','.','2','.','.','.','6'}),
                                        vector<char>({'.','6','.','.','.','.','2','8','.'}),
                                        vector<char>({'.','.','.','4','1','9','.','.','5'}),
                                        vector<char>({'.','.','.','.','8','.','.','7','9'})
                                });
    assert(solution.solveSudoku(input1));

    return 0;
}