/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool solve(TreeNode* node, int min_val, int max_val) {
        if (node == nullptr) {
            return true;
        }

        // Check if the current node's value is within the valid range
        if (node->val <= min_val || node->val >= max_val) {
            return false;
        }

        // Recursively check the left and right subtrees
        return solve(node->left, min_val, node->val) &&
               solve(node->right, node->val, max_val);
    }
    
int Solution::isValidBST(TreeNode* A) 
{
    return solve(A, INT_MIN, INT_MAX);
}


