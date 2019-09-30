// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include "themes/utils/utils.hpp"

#include <vector>

using namespace std;

class Solution {
public:
    void flatten(TreeNode *root) {
        if(!root)
            return;
        TreeNode *lastright = root -> right;
        if(pre) {
            pre->left = nullptr;
            pre->right = root;
        }
        pre = root;
        flatten(root -> left);
        flatten(lastright);
    }

private:
    TreeNode *pre = nullptr;
};

int main() {
    vector<int> vec {1, 2, 5, 3, 4, INF, 6};
    TreeNode *root = getBinaryTreeFromArray(vec);

    Solution sl;
    sl.flatten(root);

    printBinaryTree(root);

    return 0;
}
