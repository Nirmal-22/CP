/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::consecutiveNodes(TreeNode* A) 
{
    if (A == NULL) return 0;
    int count = 0;
    int left = consecutiveNodes(A->left);
    int right = consecutiveNodes(A->right);
    count = left + right;
    if (A->left != NULL && (A->val+1 == A->left->val || A->val == A->left->val+1 )) 
    {
        count++;
    }
    if (A->right != NULL && (A->val + 1 == A->right->val || A->val == A->right->val+1)) 
    {
        count++;
    }
    return count;
}
