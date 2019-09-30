// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();

        if (!s.empty()) {
            if (s[0] == p[0] || p[0] == '?')
                return isMatch(s.substr(1), p.substr(1));
            else if (p[0] == '*') {
                for (int i = 0; i <= s.size(); ++i) {
                    bool result = isMatch(s.substr(i), p.substr(1));
                    if (result)
                        return true;
                }
            }
        }

        if (p[0] == '*')
            return isMatch(s, p.substr(1));

        return false;
    }
};

int main() {
    string s("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba");
    string p("a*******b");
    
    Solution sl;
    cout << sl.isMatch(s, p) << endl;
    
    return 0;
}
