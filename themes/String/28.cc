// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        else if (haystack.empty()) return -1;

        make_next(needle);

        int i = 0;
        int j = 0;

        while (i < (int)haystack.size() && j < (int)needle.size()) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }

        if (j == needle.size())
            return i - j;
        else
            return -1;
    }

private:
    void make_next(string p) {
        next.resize(p.size());
        next[0] = -1;

        int i = 0;
        int j = -1;

        while (i < (int)p.size()) {
            if (j == -1 || p[i] == p[j]) {
                ++i;
                ++j;
                if (i < (int)p.size())
                    next[i] = j;
            } else {
                j = next[j];
            }
        }

    }

    vector<int> next;
};

int main() {
    Solution sl;
    string str("hello");
    string pattern("ll");
    cout << sl.strStr(str, pattern) << endl;

    return 0;
}
