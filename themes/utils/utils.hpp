// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include <iostream>
#include <queue>
#include <vector>

const int INF = 0x3f3f3f3f;

template<typename T>
struct ListNode {
    T val;
    ListNode<T> *next;

    ListNode() = default;

    explicit ListNode(const T &x) : val(x), next(nullptr) {}
};

template<typename T>
struct RandomListNode {
    T val;
    RandomListNode<T> *next;
    RandomListNode<T> *random;

    RandomListNode() = default;

    RandomListNode(const T &_val, RandomListNode<T> *_next, RandomListNode<T> *_random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

template<typename T>
ListNode<T> *getLinkedListFromArray(T array[], int length) {
    auto head = new ListNode<T>();
    auto ptr = head;

    for (int i = 0; i < length; ++i) {
        ptr->next = new ListNode<T>(array[i]);
        ptr = ptr->next;
    }

    return head;
}

template<typename T>
void printLinkedList(ListNode<T> *head, bool hasHead = true) {
    if (hasHead) head = head->next;
    while (head) {
        std::cout << head->val << std::endl;
        head = head->next;
    }
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() = default;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printBinaryTree(TreeNode *root);
TreeNode *getBinaryTreeFromArray(std::vector<int> &vec);
