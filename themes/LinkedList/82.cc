// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include "themes/utils/utils.hpp"

class Solution {
public:
    ListNode<int> *deleteDuplicates(ListNode<int> *head) {
        if (!head || !(head->next)) return head;

        auto h_ptr = new ListNode<int>();
        h_ptr->next = head;

        auto prev = h_ptr;
        auto cur = h_ptr->next;

        cur = cur->next;
        while (cur) {
            if (cur->val == prev->next->val) {
                cur = cur->next;
            } else {
                if (cur == prev->next->next) {
                    prev = prev->next;
                } else {
                    prev->next = cur;
                }
            }
        }

        if (prev->next->next) prev->next = nullptr;

        return h_ptr->next;
    }
};

int main() {
    Solution sl;
    int arr[] = {1, 2, 3, 3, 4, 4, 5};
    auto list = getLinkedListFromArray(arr, 7);

    auto res = sl.deleteDuplicates(list->next);
    printLinkedList(res, false);

    return 0;
}
