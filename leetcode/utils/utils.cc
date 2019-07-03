// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include "utils.hpp"

#include <functional>

void printBinaryTree(TreeNode *root) {
    if (!root) return;

    std::queue<TreeNode *> node_queue;
    node_queue.push(root);
    int level = 1;
    int node_num = 1;
    int idx = 0;
    while (!node_queue.empty()) {
        auto p = node_queue.front();
        ++idx;
        if (p) {
            std::cout << p->val << ' ';
            node_queue.push(p->left);
            node_queue.push(p->right);
        } else {
            std::cout << 'n' << ' ';
        }

        node_queue.pop();

        if (idx == node_num) {
            idx = 0;
            node_num *= 2;
            ++level;
            std::cout << '\n';
        }
    }
    std::cout << '\n';
}

TreeNode *getBinaryTreeFromArray(std::vector<int> &vec) {
    if (vec.empty()) return nullptr;

    std::function<TreeNode *(int)> func;

    func = [&vec, &func](int idx) -> TreeNode * {
        TreeNode *root = nullptr;

        if (idx < vec.size() && vec[idx] != INF) {
            root = new TreeNode(vec[idx]);
            root->left = func(2 * idx + 1);
            root->right = func(2 * idx + 2);
        }

        return root;
    };

    return func(0);
}
