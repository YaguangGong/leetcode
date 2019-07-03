// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include "leetcode/utils/utils.hpp"

class Solution {
public:
    ListNode<int> *reverseBetween(ListNode<int> *head, int m, int n) {
        if (!head || !(head->next) || m >= n) return head;

        auto h_ptr = new ListNode<int>();
        h_ptr->next = head;
        auto prev = h_ptr;
        auto ptr = head;

        int idx = 1;
        while (idx < m) {
            ptr = ptr->next;
            prev = prev->next;
            ++idx;
        }

        prev->next = nullptr;
        auto tail = ptr;
        while (idx <= n) {
            auto nxt = ptr->next;
            ptr->next = prev->next;
            prev->next = ptr;
            ptr = nxt;
            ++idx;
        }

        tail->next = ptr;

        return h_ptr->next;
    }
};

int main() {
    Solution sl;

    int arr[] = {1, 2, 3, 4, 5};
    auto list = getLinkedListFromArray(arr, 5);

    auto res = sl.reverseBetween(list->next, 2, 4);
    printLinkedList(res, false);

    return 0;
}
