// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include "themes/utils/utils.hpp"

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        root = nullptr;
        dfs(root, preorder, 0, preorder.size(), inorder, 0, inorder.size());
        return root;
    }

private:
    void dfs(TreeNode*& root, vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end) {
        if (pre_start >= pre_end) return;

        int val = preorder[pre_start];
        auto p = find(inorder.begin() + in_start, inorder.begin() + in_end, val);
        root = new TreeNode(val);
        int llen = distance(inorder.begin() + in_start, p);
        int rlen = in_end - in_start - llen - 1;
        dfs(root->left, preorder, pre_start + 1, pre_start + 1 + llen, inorder, in_start, in_start + llen);
        dfs(root->right, preorder, pre_start + 1 + llen, pre_end, inorder, in_start + llen + 1, in_end);
    }

    TreeNode *root;
};

int main() {
    Solution sl;

    vector<int> preorder {3,9,20,15,7};
    vector<int> inorder {9,3,15,20,7};

    TreeNode *root = sl.buildTree(preorder, inorder);

    printBinaryTree(root);

    return 0;
}
