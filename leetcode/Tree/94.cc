// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include "leetcode/utils/utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        function<void(TreeNode *)> func;
        func = [&vec, &func](TreeNode *root) -> void {
            if (!root) return ;
            func(root->left);
            vec.push_back(root->val);
            func(root->right);
        };
        func(root);
        return vec;
    }
};

int main() {
    Solution sl;

    vector<int> vec = {1, 2, 3, 4, 5};
    TreeNode *root = getBinaryTreeFromArray(vec);

//    printBinaryTree(root);
    auto res = sl.inorderTraversal(root);

    for (int re : res) {
        cout << re << ' ';
    }
    cout << '\n';

    return 0;
}
