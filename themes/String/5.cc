//
// Created by Yaguang on 2019/7/13.
//

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int start = 0;
        int max_len = 1;
        for(int j = 0; j < s.size(); ++j) {
            for(int i = 0; i <= j; ++i) {
                if (i == j) {
                    dp[i][j] = 1;
                } else if (j - i == 1) {
                    dp[i][j] = (s[i] == s[j]) ? 1 : 0;
                } else {
                    if (s[i] == s[j] && dp[i+1][j-1] == 1) {
                        dp[i][j] = 1;
                    }
                }

                if(dp[i][j] == 1 && max_len < j - i + 1) {
                    start = i;
                    max_len = j - i + 1;
                }
            }
        }

        return s.substr(start, max_len);
    }
};

int main() {

}