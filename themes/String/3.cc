//
// Created by Yaguang on 2019/7/13.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();

        unordered_map<char, int> map;
        int longest = 0;

        int i = 0;
        int j = 0;
        int current_len = 0;
        while(i < s.size() && j < s.size()) {
            auto got = map.find(s[j]);
            if (got == map.end()) {
                map.insert(make_pair(s[j], j));
                ++current_len;
                if (current_len > longest) {
                    longest = current_len;
                }
            } else {
                int pos = got->second;
                for (int k = i; k < pos; ++k) {
                    map.erase(s[k]);
                }
                map[s[pos]] = j;
                i = pos + 1;
                current_len = j - i + 1;
            }
            ++j;
        }

        return longest;
    }
};

int main() {
    string s("bbtablud");
    Solution sl;
    cout << sl.lengthOfLongestSubstring(s) << endl;

    return 0;
}