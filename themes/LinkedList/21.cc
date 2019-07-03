// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include "themes/utils/utils.hpp"

class Solution {
public:
    ListNode<int> *mergeTwoLists(ListNode<int> *l1, ListNode<int> *l2) {
        if (!l1 && !l2) return nullptr;
        auto head = new ListNode<int>();
        auto ptr = head;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                ptr->next = l1;
                ptr = ptr->next;
                l1 = l1->next;
            } else {
                ptr->next = l2;
                ptr = ptr->next;
                l2 = l2->next;
            }
        }

        if (l1) ptr->next = l1;
        if (l2) ptr->next = l2;

        return head->next;
    }
};

int main() {
    Solution sl;
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    auto list1 = getLinkedListFromArray(arr1, 3);
    auto list2 = getLinkedListFromArray(arr2, 3);
    auto res = sl.mergeTwoLists(list1->next, list2->next);
    printLinkedList(res, false);

    return 0;
}
