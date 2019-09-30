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

TreeNode *getBinaryTreeFromArray(std::vector<int> &vec) { // TODO
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

BSTree::~BSTree() {
    std::function<void(TreeNode*)> func = [&func](TreeNode* root) {
        if (root) {
            func(root->left);
            func(root->right);
            delete root;
        }
    };
}

TreeNode* BSTree::searchNode(int val) {
    std::function<TreeNode*(TreeNode*, int)> func = [&func](TreeNode* root, int val) -> TreeNode* {
        if (root) {
            if (val == root->val) {
                return root;
            } else if(val < root->val) {
                return func(root->left, val);
            } else {
                return func(root->right, val);
            }
        }

        return nullptr;
    };

    return func(_root, val);
}

bool BSTree::insertNode(int val) {
    std::function<bool(TreeNode*&, int)> func = [&func, this](TreeNode*& root, int val) -> bool {
        if (root) {
            if (val == root->val) {
                return false;
            } else if(val < root->val) {
                func(root->left, val);
            } else {
                func(root->right, val);
            }
        } else {
            root = new TreeNode(val);
            ++node_num;
            return true;
        }
    };

    return func(_root, val);
}

bool BSTree::deleteNode(int val) {
    TreeNode* current = _root;
    TreeNode* parent = nullptr;
    while(current) {
        if (val == current->val) {
            break;
        } else if(val < current->val) {
            parent = current;
            current = current->left;
        } else {
            parent = current;
            current = current->right;
        }
    }

    if (!current) return false;

    if (!current->left) {
        if (!parent) {
            _root = current->right;
            delete current;
            --node_num;
        } else if(current == parent->left) {
            parent->left = current->right;
        } else if(current == parent->right) {
            parent->right = current->right;
        }
    } else {
        TreeNode* del = current->left;
        TreeNode* del_parent = current;
        while(del->right) {
            del_parent = del;
            del = del->right;
        }
        if (del_parent == current) {
            current->left = del->left;
        } else {
            del_parent->right = del->left;
        }
        current->val = del->val;
        delete del;
        --node_num;
    }

    return true;
}

void BSTree::preOrderTraversal() {
    std::function<void(TreeNode*)> func = [&func](TreeNode* root) {
        if (root) {
            std::cout << root->val << " ";
            func(root->left);
            func(root->right);
        }
    };

    func(_root);
};

void BSTree::inOrderTraversal() {
    std::function<void(TreeNode*)> func = [&func](TreeNode* root) {
        if (root) {
            func(root->left);
            std::cout << root->val << " ";
            func(root->right);
        }
    };

    func(_root);
};

void BSTree::postOrderTraversal() {
    std::function<void(TreeNode*)> func = [&func](TreeNode* root) {
        if (root) {
            func(root->left);
            func(root->right);
            std::cout << root->val << " ";
        }
    };

    func(_root);
};
