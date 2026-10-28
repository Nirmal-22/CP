// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode* root) {
        function<bool(TreeNode*, long long, long)> helper = [&](TreeNode* node, long long low, long long high){
            if(!node) return true;
            if(node->val<=low || node->val>=high) return false;
            return helper(node->left, low, node->val) && helper(node->right, node->val, high);
        };

        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};
