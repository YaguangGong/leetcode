// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        if (board.empty()) return 0;
        else if (hand.empty()) return -1;

        unordered_map<char, int> m;
        for (auto c: hand) {
            ++m[c];
        }

        int result = hand.size() + 1;
        dfs(board, m, 0, result);

        return result == hand.size() + 1 ? -1 : result;
    }

private:
    void dfs(string board, unordered_map<char, int> &m, int current, int &result) {
        while (!board.empty()) {
            int cnt = 1;
            bool flag = false;
            for (auto it = board.begin() + 1; it != board.end(); ++it) {
                if (*it == *(it - 1)) {
                    ++cnt;
                } else {
                    if (cnt >= 3) {
                        it = board.erase(it - cnt, it);
                        flag = true;
                    }
                    cnt = 1;
                }
            }
            if (cnt >= 3) {
                board.erase(board.end() - cnt, board.end());
                flag = true;
            }
            if (!flag)
                break;
        }
        if (board.empty()) {
            if (current < result)
                result = current;
            return ;
        }

        auto it = board.begin() + 1;
        for (; it != board.end(); ++it) {
            if (*it != *(it - 1)) {
                if (m[*(it - 1)] > 0) {
                    --m[*(it - 1)];
                    it = board.insert(it, *(it - 1));
                    dfs(board, m, current+1, result);
                    ++m[*it];
                    it = board.erase(it);
                }
            }
        }
        if (m[*(it - 1)] > 0) {
            --m[*(it - 1)];
            it = board.insert(it, *(it - 1));
            dfs(board, m, current+1, result);
            ++m[*it];
            it = board.erase(it);
        }
    }
};

int main() {
    string board("WWGWGW");
    string hand("GWBWR");

    Solution sl;
    cout << sl.findMinStep(board, hand) << endl;

    return 0;
}
