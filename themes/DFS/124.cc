// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include "themes/utils/utils.hpp"

#include <limits>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int result = numeric_limits<int>::min();
        if (root->left) {
            result = max(result, maxPathSum(root->left));
        }

        if (root->right) {
            result = max(result, maxPathSum(root->right));
        }

        int l = helper(root->left);
        int r = helper(root->right);
        result = max(result, max(l, r) + root->val);
        result = max(result, max(0, l + r) + root->val);

        return result;
    }

private:
    int helper(TreeNode* root) {
        if (!root) return 0;

        auto got = m.find(root);
        if (got != m.end())
            return m[root];
        else {
            int result = root->val;
            result = max(result, max(helper(root->left), helper(root->right)) + result);
            m[root] = result;
            return result;
        }
    }

    unordered_map<TreeNode*, int> m;
};

int main() {
    vector<int> v {5, 4, 8, 11, INF, 13, 4, 7, 2, INF, INF, INF, 1};

    TreeNode *root = getBinaryTreeFromArray(v);

    Solution sl;

    cout << sl.maxPathSum(root);

    return 0;
}
