// 124. Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int mx=INT_MIN;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if(!node) return 0;
            int l = max(0, dfs(node->left));
            int r = max(0, dfs(node->right));

            mx = max(mx, node->val + l + r);
            return node->val +  max(l,r);
        };
        dfs(root);
        return mx;
    }
};
