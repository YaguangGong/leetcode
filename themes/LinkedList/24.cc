// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include "themes/utils/utils.hpp"

class Solution {
public:
    ListNode<int> *swapPairs(ListNode<int> *head) {
        auto h_ptr = new ListNode<int>();
        h_ptr->next = head;

        auto prev = h_ptr;
        auto first = h_ptr->next;
        if (!first || !(first->next)) return head;

        auto second = first->next;

        while (first && second) {
            prev->next = second;
            first->next = second->next;
            second->next = first;
            prev = first;
            first = first->next;
            if (!first)
                break;
            second = first->next;
        }

        return h_ptr->next;
    }
};

int main() {
    Solution sl;

    int arr[] = {1, 2, 3, 4};
    auto list = getLinkedListFromArray(arr, 4);

    auto res = sl.swapPairs(list->next);
    printLinkedList(res, false);

    return 0;
}
