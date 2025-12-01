/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool isMirror(TreeNode* leftTree, TreeNode* rightTree) 
{
    if (!leftTree && !rightTree) 
        return true;
    
    if (!leftTree || !rightTree) 
        return false;
    
    return (leftTree->val == rightTree->val) &&
           isMirror(leftTree->left, rightTree->right) &&
           isMirror(leftTree->right, rightTree->left);
}

int Solution::isSymmetric(TreeNode* A) 
{
    if (!A) 
    return true;
    
    return isMirror(A->left, A->right)?1:0;
}
