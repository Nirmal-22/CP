/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int getHeight(TreeNode* root) 
{
    if (root == NULL) 
        return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if (leftHeight == -1 || rightHeight == -1) return -1;
    if (abs(leftHeight - rightHeight) > 1) return -1;

    return std::max(leftHeight, rightHeight) + 1;
}
int Solution::isBalanced(TreeNode* A) {
    return getHeight(A)!=-1?1:0;
}
