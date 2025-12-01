/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) 
{
    if (A == nullptr) 
        return 0; 
    
    if (A->left == nullptr)
        return minDepth(A->right) + 1;
    
    if (A->right == nullptr)
        return minDepth(A->left) + 1;
    
    return std::min(minDepth(A->left), minDepth(A->right)) + 1;
}
