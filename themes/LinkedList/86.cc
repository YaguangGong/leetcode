// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include "themes/utils/utils.hpp"

class Solution {
public:
    ListNode<int> *partition(ListNode<int> *head, int x) {
        if (!head || !(head->next)) return head;

        auto h_left = new ListNode<int>();
        auto p_left = h_left;
        auto h_right = new ListNode<int>();
        auto p_right = h_right;

        auto ptr = head;
        while (ptr) {
            if (ptr->val < x) {
                p_left->next = ptr;
                ptr = ptr->next;
                p_left = p_left->next;
                p_left->next = nullptr;
            } else {
                p_right->next = ptr;
                ptr = ptr->next;
                p_right = p_right->next;
                p_right->next = nullptr;
            }
        }
        p_left->next = h_right->next;

        return h_left->next;
    }
};

int main() {
    Solution sl;
    int arr[] = {1, 4, 3, 2, 5, 2};
    auto list = getLinkedListFromArray(arr, 6);

    auto res = sl.partition(list->next, 3);
    printLinkedList(res, false);

    return 0;
}
