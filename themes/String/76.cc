// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return string();

        int start = 0;
        int min_len = s.size() + 1;
        int doneCnt = 0;
        int uniqueCnt = 0;
        unordered_map<char, int> desired, actual;
        for (auto c: t) {
            if (desired.find(c) == desired.end()) ++uniqueCnt;
            ++desired[c];
        }

        int l = 0;
        int r = -1;
        while (r < (int)s.size()) {
            if (doneCnt < uniqueCnt) {
                ++r;
                if (desired.find(s[r]) != desired.end()) {
                    ++actual[s[r]];
                    if (actual[s[r]] == desired[s[r]]) ++doneCnt;
                }
            } else {
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    start = l;
                }

                if (desired.find(s[l]) != desired.end()) {
                    --actual[s[l]];
                    if (actual[s[l]] < desired[s[l]]) --doneCnt;
                }
                ++l;
            }
        }

        return min_len == s.size() + 1 ? string() : s.substr(start, min_len);
    }
};

int main() {
    string s("ADOBECODEBANC");
    string t("ABC");

    Solution sl;
    cout << sl.minWindow(s, t) << endl;

    return 0;
}
