// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) return vector<int>();
        if (words.size() * words[0].size() > s.size()) return vector<int>();

        unordered_map<string, int> all_word;
        unordered_map<string, int> seen_word;

        for (auto word: words) {
            ++all_word[word];
        }

        int word_len = words[0].size();
        vector<int> result;

        for (int i = 0; i < s.size(); ++i) {
            int match = 0;
            seen_word.clear();
            for (int j = i; j + word_len <= s.size(); j += word_len) {
                string sub = s.substr(j, word_len);
                ++seen_word[sub];
                if (all_word.find(sub) == all_word.end() || seen_word[sub] > all_word[sub])
                    break;
                ++match;
                if (match == words.size())
                    result.push_back(i);
            }
        }

        return result;
    }

};

int main() {
    string s("wordgoodgoodgoodbestword");
    vector<string> words = {"word", "good", "best", "good"};

    Solution sl;
    auto result = sl.findSubstring(s, words);

    cout << "stop" << endl;

    return 0;
}
