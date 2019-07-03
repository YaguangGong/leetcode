// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include "leetcode/utils/utils.hpp"

class Solution {
public:
    ListNode<int> *rotateRight(ListNode<int> *head, int k) {
        if (!head || !(head->next)) return head;

        int len = 1;
        auto ptr = head;

        while (ptr->next) {
            ++len;
            ptr = ptr->next;
        }
        if (k % len == 0) return head;

        ptr->next = head;
        k = len - k % len;

        ptr = head;
        while (--k) {
            ptr = ptr->next;
        }

        head = ptr->next;
        ptr->next = nullptr;

        return head;
    }
};

int main() {
    Solution sl;

    int arr[] = {1, 2, 3, 4, 5};
    auto list = getLinkedListFromArray(arr, 5);

    auto res = sl.rotateRight(list->next, 2);
    printLinkedList(res, false);

    return 0;
}
