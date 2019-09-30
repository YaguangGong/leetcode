// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return string("0");

        int len1 = num1.size();
        int len2 = num2.size();
        string result(len1 + len2, '0');

        int num_zeros = 0;
        int last1 = len1 - 1;
        int last2 = len2 - 1;
        while (last1 >= 0 && num1[last1] == '0') {
            --last1;
            ++num_zeros;
        }

        while (last2 >= 0 && num2[last2] == '0') {
            --last2;
            ++num_zeros;
        }

        int last_result = len1 + len2 - 1 - num_zeros;
        int carry = 0;
        for (int i = last2; i >= 0; --i) {
            int current_pos = last_result;
            --last_result;
            carry = 0;
            if (num2[i] == '0')
                continue;
            for (int j = last1; j >= 0; --j) {
                int i1 = num1[j] - '0';
                int i2 = num2[i] - '0';
                int mul = i1 * i2;
                int temp = (result[current_pos] - '0') + (mul % 10) + carry;
                result[current_pos] = temp % 10 + '0';
                carry = mul / 10 + temp / 10;
                --current_pos;
            }
            if (carry > 0)
                result[current_pos] = carry + '0';
        }

        if (carry > 0)
            result[0] = carry + '0';

        if (result[0] == '0')
            result.erase(result.begin());


        return result;
    }
};

int main() {
    string s1("9");
    string s2("99");

    Solution sl;
    cout << sl.multiply(s1, s2) << endl;

    return 0;
}
