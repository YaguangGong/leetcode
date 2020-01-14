// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// TODO: TLE
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        vector<vector<string>> res;

        dfs(tickets, res, vector<string>{"JFK"}, unordered_set<int>(), tickets.size());

        auto func = [](const vector<string> &l, const vector<string> &r) {
            string cur_l;
            string cur_r;
            for (int i = 0; i < l.size(); ++i) {
                cur_l += l[i];
                cur_r += r[i];
            }
            return cur_l.compare(cur_r) < 0;
        };

        for (auto &it_res: res) {
            string cur;
            if (it_res.empty())
                cout << "empty!!!" << endl;
        }

        sort(res.begin(), res.end(), func);

        return res[0];
    }

private:
    void
    dfs(vector<vector<string>> &tickets, vector<vector<string>> &res, vector<string> local, unordered_set<int> used,
        int num_trip) {
        if (num_trip == local.size() - 1 && num_trip == used.size()) {
            res.emplace_back(local);
            return;
        }

        string last = local.back();
        for (int i = 0; i < tickets.size(); ++i) {
            if (used.find(i) == used.end()) {
                string from = tickets[i][0];
                string to = tickets[i][1];

                if (last == from) {
                    local.emplace_back(to);
                    used.emplace(i);
                    dfs(tickets, res, local, used, num_trip);
                    used.erase(i);
                    local.pop_back();
                }
            }
        }
    }
};

int main() {
    vector<vector<string>> input = {{"EZE", "TIA"},
                                    {"EZE", "HBA"},
                                    {"AXA", "TIA"},
                                    {"JFK", "AXA"},
                                    {"ANU", "JFK"},
                                    {"ADL", "ANU"},
                                    {"TIA", "AUA"},
                                    {"ANU", "AUA"},
                                    {"ADL", "EZE"},
                                    {"ADL", "EZE"},
                                    {"EZE", "ADL"},
                                    {"AXA", "EZE"},
                                    {"AUA", "AXA"},
                                    {"JFK", "AXA"},
                                    {"AXA", "AUA"},
                                    {"AUA", "ADL"},
                                    {"ANU", "EZE"},
                                    {"TIA", "ADL"},
                                    {"EZE", "ANU"},
                                    {"AUA", "ANU"}};

    Solution sl;
    auto res = sl.findItinerary(input);
    for (auto &it: res) {
        cout << it << endl;
    }

    return 0;
}
