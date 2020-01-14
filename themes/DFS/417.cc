// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if (matrix.empty() || matrix[0].empty()) return res;

        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            dfs(matrix, memo, i, 0, 1);
            dfs(matrix, memo, i, matrix[0].size()-1, 2);
        }
        for (int i = 0; i < matrix[0].size(); ++i) {
            dfs(matrix, memo, 0, i, 1);
            dfs(matrix, memo, matrix.size()-1, i, 2);
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (memo[i][j] == 3) res.push_back(vector<int>{i, j});
            }
        }

        return res;
    }

private:
    void dfs(vector<vector<int>> &matrix, vector<vector<int>> &memo, int r, int c, int mask) {
        memo[r][c] |= mask;

        vector<int> dr = {0, 0, 1, -1};
        vector<int> dc = {1, -1, 0, 0};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr > matrix.size()-1 || nc < 0 || nc > matrix[0].size()-1) continue;
            if (matrix[nr][nc] < matrix[r][c] || memo[nr][nc] & mask) continue;

            dfs(matrix, memo, nr, nc, mask);
        }
    }
};

int main() {
    vector<vector<int>> graph = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    Solution sl;

    auto res = sl.pacificAtlantic(graph);
    for (auto &ele: res) {
        cout << ele[0] << " " << ele[1] << endl;
    }

    return 0;
}
