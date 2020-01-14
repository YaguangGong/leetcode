// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: yggong@mobvoi.com (Yaguang Gong)

#include <queue>
#include <unordered_map>

#include "themes/utils/utils.hpp"

using namespace std;

class Solution {
public:
    int rob(TreeNode* root) {
        if (!root) return 0;

        return max(dfs(root, true), dfs(root, false));
    }

private:
    unordered_map<TreeNode *, int> tm;
    unordered_map<TreeNode *, int> fm;

    int dfs(TreeNode *root, bool take) {
        if (take) {
            if (tm.find(root) != tm.end())
                return tm[root];
        } else {
            if (fm.find(root) != fm.end())
                return fm[root];
        }

        if (root->left && !root->right) {
            if (take) {
                tm[root] = root->val + dfs(root->left, false);
            } else {
                fm[root] = max(dfs(root->left, true), dfs(root->left, false));
            }
        } else if (!root->left && root->right) {
            if (take) {
                tm[root] = root->val + dfs(root->right, false);
            } else {
                fm[root] = max(dfs(root->right, true), dfs(root->right, false));
            }
        } else if (root->left && root->right) {
            if (take) {
                tm[root] = root->val + dfs(root->left, false) + dfs(root->right, false);
            } else {
                fm[root] = max(dfs(root->left, true), dfs(root->left, false)) + max(dfs(root->right, true), dfs(root->right, false));
            }
        } else {
            if (take) {
                tm[root] = root->val;
            } else {
                fm[root] = 0;
            }
        }

        if (take)
            return tm[root];
        else
            return fm[root];
    }
};

int main() {
    vector<int> arr = {3, 2, 3, INF, 3, INF, 1};
    auto root = getBinaryTreeFromArray(arr);

    Solution sl;
    cout << sl.rob(root) << endl;

    return 0;
}
