// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (!board.empty()) {
            auto len_r = board.size();
            auto len_c = board[0].size();

            for (auto i = 0; i < len_r; ++i) {
                for (auto j = 0; j < len_c; ++j) {
                    if (board[i][j] == 'O' && (i == 0 || i == len_r - 1 || j == 0 || j == len_c - 1))
                        dfs(board, i, j, len_r, len_c);
                }
            }

            for (auto i = 0; i < len_r; ++i) {
                for (auto j = 0; j < len_c; ++j) {
                    if (board[i][j] == '*')
                        board[i][j] = 'O';
                    else if (board[i][j] == 'O')
                        board[i][j] = 'X';
                }
            }
        }
    }

private:
    void dfs(vector<vector<char>>& vec, int row, int column, int len_r, int len_c) {
        vec[row][column] = '*';
        if (row > 0 && vec[row-1][column] == 'O')
            dfs(vec, row-1, column, len_r, len_c);
        if (row < len_r-1 && vec[row+1][column] == 'O')
            dfs(vec, row+1, column, len_r, len_c);
        if (column > 0 && vec[row][column-1] == 'O')
            dfs(vec, row, column-1, len_r, len_c);
        if (column < len_c-1 && vec[row][column+1] == 'O')
            dfs(vec, row, column+1, len_r, len_c);
    }
};

int main() {
    return 0;
}
