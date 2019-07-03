// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include "leetcode/utils/utils.hpp"

class Solution {
public:
    ListNode<int> *removeNthFromEnd(ListNode<int> *head, int n) {
        auto h_ptr = new ListNode<int>();
        h_ptr->next = head;

        auto prev = h_ptr;
        auto cur = h_ptr->next;
        auto front = cur;
        while (--n) {
            front = front->next;
        }

        while (front->next) {
            prev = prev->next;
            cur = cur->next;
            front = front->next;
        }

        prev->next = cur->next;
        return h_ptr->next;
    }
};

int main() {
    Solution sl;
    int arr[] = {1, 2, 3, 4, 5};
    auto head = getLinkedListFromArray(arr, 5);
    auto res = sl.removeNthFromEnd(head->next, 2);
    printLinkedList(res, false);

    return 0;
}
