// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include "leetcode/utils/utils.hpp"

#include <map>

class Solution {
public:
    RandomListNode<int> *copyRandomList(RandomListNode<int> *head) {
        if (!head) return head;

        auto h_ptr = new RandomListNode<int>();
        auto new_ptr = h_ptr;

        auto ptr = head;
        while (ptr) {
            auto it = node_map.find(ptr);
            RandomListNode<int> *new_node = nullptr;
            if (it == node_map.end()) {
                new_node = new RandomListNode<int>(ptr->val, nullptr, nullptr);
                node_map.insert(std::make_pair(ptr, new_node));
            } else {
                new_node = it->second;
            }

            if (ptr->random) {
                it = node_map.find(ptr->random);
                RandomListNode<int> *new_random_node = nullptr;
                if (it == node_map.end()) {
                    new_random_node =
                            new RandomListNode<int>(ptr->random->val, nullptr, nullptr);
                    node_map.insert(std::make_pair(ptr->random, new_random_node));
                } else {
                    new_random_node = it->second;
                }
                new_node->random = new_random_node;
            }

            new_ptr->next = new_node;
            new_ptr = new_ptr->next;
            ptr = ptr->next;
        }

        return h_ptr->next;
    }

private:
    std::map<RandomListNode<int> *, RandomListNode<int> *> node_map;
};

int main() {
    return 0;
}
