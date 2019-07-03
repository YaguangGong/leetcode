// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include "leetcode/utils/utils.hpp"

#include <unordered_set>

class Solution {
public:
    ListNode<int> *detectCycle(ListNode<int> *head) {
        if (!head || !(head->next)) return nullptr;

        auto ptr = head;
        while (ptr) {
            auto res = node_set.find(ptr);
            if (res == node_set.end()) {
                node_set.insert(ptr);
                ptr = ptr->next;
            } else {
                return ptr;
            }
        }

        return nullptr;
    }

private:
    std::unordered_set<ListNode<int> *> node_set;
};

int main() {

}
