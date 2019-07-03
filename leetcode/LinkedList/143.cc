// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include "leetcode/utils/utils.hpp"

class Solution {
public:
    void reorderList(ListNode<int> *head) {
        if (!head || !(head->next) || !(head->next->next)) return;

        auto p = head;
        auto q = head->next;

        while (q && q->next) {
            p = p->next;
            q = q->next->next;
        }

        q = p->next;
        p->next = nullptr;
        while (q) {
            auto t = q->next;
            q->next = p->next;
            p->next = q;
            q = t;
        }

        q = p->next;
        p->next = nullptr;
        p = head;

        while (p && q) {
            auto pn = p->next;
            auto qn = q->next;
            q->next = p->next;
            p->next = q;
            p = pn;
            q = qn;
        }
    }
};

int main() {
    Solution sl;
    int arr[] = {1, 2, 3, 4, 5};
    auto list = getLinkedListFromArray(arr, 5);
    sl.reorderList(list->next);
    printLinkedList(list);

    return 0;
}
